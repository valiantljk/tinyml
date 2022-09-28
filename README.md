# Tinyml 2022

## Step 1: How to Train
'''
 python3 ray_tune.py
'''
Best training parameters

{'batchsz': 32, 'lr': 0.0023538429427261503, 'epoch': 20, 'drop': 0.4, 'momentum': 0.2}

The model is saved in training/tuned_model
'''
ray_tuned_IEGM_net.pkl
ray_tuned_IEGM_net_state_dict.pkl
'''

## Step 2: Convert to ONNX
'''
from help_code_demo import pytorch2onnx
pytorch2onnx('./tuned_model/ray_tuned_IEGM_net.pkl', './tuned_model/model_1', 1250)
'''

## Step 3: Code generation

Following https://github.com/tinymlcontest/tinyml_contest2022_demo_example/blob/master/README-Cube.md and https://github.com/tinymlcontest/tinyml_contest2022_demo_evaluation/blob/main/How%20to%20validate%20X-CUBE-AI%20model%20on%20board.md

Generated codes are saved in folder inference/

## TinyML Contest:
* https://tinymlcontest.github.io/TinyML-Design-Contest/Problems.html

## Forked from:
* https://github.com/tinymlcontest/tinyml_contest2022_demo_example

## Training Data:
* https://drive.google.com/file/d/11lOiocENt7TVRqwYbUkIgd1_-ZCUNIrH/view


## Hyper-Parameter Tuning:
* https://docs.ray.io/en/releases-2.0.0/tune/examples/tune-pytorch-cifar.html

## Model Optimization on Device:
* https://github.com/mit-han-lab/mcunet
* https://github.com/mit-han-lab/tinyengine

## Deploy on Board:
* https://github.com/tinymlcontest/tinyml_contest2022_demo_example/blob/master/README-Cube.md