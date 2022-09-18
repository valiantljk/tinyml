#run ray tune on arnold
launch --cpu 20 --memory 40 --gpu 4 --type v100-32g -- python3 ray_tune.
#model saved in tuned_model
#Best Acc: 0.92516 


#run example code on arnold
launch --cpu 20 --memory 40 --gpu 1 --type v100-32g -- python3 training_save_deep_models.py  --epoch 5 --lr 0.0023433893576339684 --batchsz 32 --path_data ../../data/tinyml/
#model saved in saved_model

