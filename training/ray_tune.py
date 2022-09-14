import argparse
import torch
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
import torch.nn as nn
import torch.optim as optim
from help_code_demo import ToTensor, IEGM_DataSET
from models.model_1 import IEGMNet
from torch.utils.data import random_split


import ray
from ray import tune
from ray.air import session
from ray.air.checkpoint import Checkpoint
from ray.tune.schedulers import ASHAScheduler

def train(config):
    #Hyperparameters
    BATCH_SIZE = config["batchsz"]
    BATCH_SIZE_TEST = config["batchsz"]
    LR = config["lr"]
    EPOCH = config["epoch"]
    SIZE = 1250
    path_data = "/Users/dr6jl/Documents/tinyml/data/tinyml/"
    path_indices = "/Users/dr6jl/Documents/tinyml/training/data_indices/"

    # Instantiating NN
    net = IEGMNet()
    net.train()
    device = "cuda:0" if torch.cuda.is_available() else "cpu"
    net = net.float().to(device)

    # Start dataset loading
    trainset = IEGM_DataSET(root_dir=path_data,
                            indice_dir=path_indices,
                            mode='train',
                            size=SIZE,
                            transform=transforms.Compose([ToTensor()]))

    

    # testset = IEGM_DataSET(root_dir=path_data,
    #                        indice_dir=path_indices,
    #                        mode='test',
    #                        size=SIZE,
    #                        transform=transforms.Compose([ToTensor()]))

    # testloader = DataLoader(testset, batch_size=BATCH_SIZE_TEST, shuffle=True, num_workers=0)

    test_abs = int(len(trainset) * 0.8)
    train_subset, val_subset = random_split(
        trainset, [test_abs, len(trainset) - test_abs])

    trainloader = DataLoader(train_subset, batch_size=BATCH_SIZE, shuffle=True, num_workers=0)

    valloader = DataLoader(val_subset, batch_size=BATCH_SIZE_TEST, shuffle=True, num_workers=0)

    print("Training Dataset loading finish.")

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(net.parameters(), lr=LR)

    # To restore a checkpoint, use `session.get_checkpoint()`.
    loaded_checkpoint = session.get_checkpoint()
    if loaded_checkpoint:
        with loaded_checkpoint.as_directory() as loaded_checkpoint_dir:
           model_state, optimizer_state = torch.load(os.path.join(loaded_checkpoint_dir, "checkpoint.pt"))
        net.load_state_dict(model_state)
        optimizer.load_state_dict(optimizer_state)

    epoch_num = EPOCH

    Train_loss = []
    Train_acc = []
    Test_loss = []
    Test_acc = []

    print("Start training")
    for epoch in range(epoch_num):  # loop over the dataset multiple times (specify the #epoch)

        running_loss = 0.0
        correct = 0.0
        accuracy = 0.0
        i = 0
        for j, data in enumerate(trainloader, 0):
            inputs, labels = data['IEGM_seg'], data['label']
            inputs = inputs.float().to(device)
            labels = labels.to(device)

            optimizer.zero_grad()
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            _, predicted = torch.max(outputs.data, 1)
            correct += (predicted == labels).sum()
            accuracy += correct / BATCH_SIZE
            correct = 0.0

            running_loss += loss.item()
            i += 1

        print('[Epoch, Batches] is [%d, %5d] \nTrain Acc: %.5f Train loss: %.5f' %
              (epoch + 1, i, accuracy / i, running_loss / i))

        Train_loss.append(running_loss / i)
        Train_acc.append((accuracy / i).item())

        running_loss = 0.0
        accuracy = 0.0

        correct = 0.0
        total = 0.0
        i = 0.0
        running_loss_test = 0.0

        for data_test in valloader:
            net.eval()
            IEGM_test, labels_test = data_test['IEGM_seg'], data_test['label']
            IEGM_test = IEGM_test.float().to(device)
            labels_test = labels_test.to(device)
            outputs_test = net(IEGM_test)
            _, predicted_test = torch.max(outputs_test.data, 1)
            total += labels_test.size(0)
            correct += (predicted_test == labels_test).sum()

            loss_test = criterion(outputs_test, labels_test)
            running_loss_test += loss_test.item()
            i += 1

        print('Test Acc: %.5f Test Loss: %.5f' % (correct / total, running_loss_test / i))

        Test_loss.append(running_loss_test / i)
        Test_acc.append((correct / total).item())

    os.mkdir("tuned_model",exist_ok=True)
    torch.save((net,net.state_dict()),"tuned_models/checkpoint.pt")
    checkpoint = Checkpoint.from_directory("tuned_models")
    session.report({"loss":Test_loss,"accuracy":Test_acc}, checkpoint = checkpoint)

    print('Finish training')

def test_best_model(best_result,config):
    best_trained_model = IEGMNet()
    best_trained_model.train()
    device = "cuda:0" if torch.cuda.is_available() else "cpu"
    best_trained_model.to(device)

    checkpoint_path = os.path.join(best_result.checkpoint.to_directory(), "checkpoint.pt")

    model_state, optimizer_state = torch.load(checkpoint_path)
    best_trained_model.load_state_dict(model_state)
    correct = 0.0
    total = 0.0
    i = 0.0
    running_loss_test = 0.0
    SIZE = 1250
    path_data = "/Users/dr6jl/Documents/tinyml/data/tinyml"
    path_indices = "/Users/dr6jl/Documents/tinyml/training/data_indices"
    testset = IEGM_DataSET(root_dir=path_data,
                           indice_dir=path_indices,
                           mode='test',
                           size=SIZE,
                           transform=transforms.Compose([ToTensor()]))

    testloader = DataLoader(testset, batch_size=config["BATCH_SIZE_TEST"], shuffle=True, num_workers=0)

    for data_test in testloader:
        best_trained_model.eval()
        IEGM_test, labels_test = data_test['IEGM_seg'], data_test['label']
        IEGM_test = IEGM_test.float().to(device)
        labels_test = labels_test.to(device)
        outputs_test = best_trained_model(IEGM_test)
        _, predicted_test = torch.max(outputs_test.data, 1)
        total += labels_test.size(0)
        correct += (predicted_test == labels_test).sum()

        loss_test = criterion(outputs_test, labels_test)
        running_loss_test += loss_test.item()
        i += 1

    print('Best trial Test Acc: %.5f Test Loss: %.5f' % (correct / total, running_loss_test / i))



def tune_main(num_samples=10, max_num_epochs=10, gpus_per_trial=2):
    config = {
        "batchsz": tune.choice([8,32,64]),
        "lr": tune.loguniform(1e-4, 1e-1),
        "epoch": tune.choice([5,10,20]),
        # "size": tune.choice([1250]),
        # "path_data":tune.choice(["../data/tinyml"]),
        # "path_indices":tune.choice(["./data_indices"])
    }
    scheduler = ASHAScheduler(
        max_t=max_num_epochs,
        grace_period=1,
        reduction_factor=2)
    
    tuner = tune.Tuner(
        tune.with_resources(
            tune.with_parameters(train),
            resources={"cpu": 2, "gpu": gpus_per_trial}
        ),
        tune_config=tune.TuneConfig(
            metric="loss",
            mode="min",
            scheduler=scheduler,
            num_samples=num_samples,
        ),
        param_space=config,
    )
    results = tuner.fit()
    
    best_result = results.get_best_result("loss", "min")

    print("Best trial config: {}".format(best_result.config))
    print("Best trial final validation loss: {}".format(
        best_result.metrics["loss"]))
    print("Best trial final validation accuracy: {}".format(
        best_result.metrics["accuracy"]))

    test_best_model(best_result,config)


if __name__ == '__main__':
    num_gpus=torch.cuda.device_count()
    if num_gpus==0:
        ns = 1
        gpt=0
    else:
        ns = num_gpus*2
        gpt=0.5
    tune_main(num_samples=ns, max_num_epochs=20, gpus_per_trial=gpt)


