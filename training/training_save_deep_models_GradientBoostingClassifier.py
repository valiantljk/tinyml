"""Example on classification using CIFAR-10."""

import time
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader
from torchvision import datasets, transforms


from torchensemble.gradient_boosting import GradientBoostingClassifier

from torchensemble.utils.logging import set_logger
import argparse
import torch
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
import torch.nn as nn
import torch.optim as optim
from help_code_demo import ToTensor, IEGM_DataSET
from models.model_1 import IEGMNet

def display_records(records, logger):
    msg = (
        "{:<28} | Testing Acc: {:.2f} % | Training Time: {:.2f} s |"
        " Evaluating Time: {:.2f} s"
    )

    print("\n")
    for method, training_time, evaluating_time, acc in records:
        logger.info(msg.format(method, acc, training_time, evaluating_time))


def main():
    # Hyperparameters

    SIZE = args.size
    path_data = args.path_data
    path_indices = args.path_indices

    n_estimators = 10
    lr = 1e-3
    weight_decay = 5e-4
    epochs = 100

    # Utils
    batch_size = 128
    # data_dir = "../../Dataset/cifar"  # MODIFY THIS IF YOU WANT
    records = []
    torch.manual_seed(0)
    # Start dataset loading
    trainset = IEGM_DataSET(root_dir=path_data,
                            indice_dir=path_indices,
                            mode='train',
                            size=SIZE,
                            transform=transforms.Compose([ToTensor()]))

    trainloader = DataLoader(trainset, batch_size=batch_size, shuffle=True, num_workers=0)
    # for j, data in enumerate(trainloader, 0):
    #     import pdb
    #     pdb.set_trace()

    testset = IEGM_DataSET(root_dir=path_data,
                           indice_dir=path_indices,
                           mode='test',
                           size=SIZE,
                           transform=transforms.Compose([ToTensor()]))

    testloader = DataLoader(testset, batch_size=batch_size, shuffle=True, num_workers=0)

    print("Training Dataset loading finish.")
    logger = set_logger("bytelife_cnn", use_tb_logger=True)    

    # GradientBoostingClassifier
    print("begin GradientBoostingClassifier")
    model = GradientBoostingClassifier(
        estimator=IEGMNet, n_estimators=n_estimators, cuda=True
    )

    # Set the optimizer
    model.set_optimizer("Adam", lr=lr, weight_decay=weight_decay)

    # Training
    tic = time.time()
    model.fit(trainloader, epochs=epochs)
    toc = time.time()
    training_time = toc - tic

    # Evaluating
    tic = time.time()
    testing_acc = model.evaluate(testloader)
    toc = time.time()
    evaluating_time = toc - tic

    records.append(
        (
            "GradientBoostingClassifier",
            training_time,
            evaluating_time,
            testing_acc,
        )
    )
    display_records(records, logger)
    print('Finish training')

    import pdb
    pdb.set_trace()



if __name__ == '__main__':
    argparser = argparse.ArgumentParser()
    argparser.add_argument('--epoch', type=int, help='epoch number', default=2)
    argparser.add_argument('--lr', type=float, help='learning rate', default=0.0001)
    argparser.add_argument('--batchsz', type=int, help='total batchsz for traindb', default=32)
    argparser.add_argument('--cuda', type=int, default=0)
    argparser.add_argument('--size', type=int, default=1250)
    # argparser.add_argument('--path_data', type=str, default='H:/Date_Experiment/data_IEGMdb_ICCAD_Contest/segments-R250'
    #                                                         '-BPF15_55-Noise/tinyml_contest_data_training/')
    argparser.add_argument('--path_data', type=str, default='/root/tinyml_contest2022_demo_example-master/training_data/')

    argparser.add_argument('--path_indices', type=str, default='./data_indices')

    args = argparser.parse_args()

    device = torch.device("cuda:" + str(args.cuda))

    print("device is --------------", device)

    main()
