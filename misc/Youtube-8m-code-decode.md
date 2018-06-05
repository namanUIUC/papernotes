# YOUTUBE - 8m (Code - Decode)

## train 

### Flags

| Name                           | Role           | Type   | Value            | Comment / Use                                                |
| ------------------------------ | -------------- | ------ | ---------------- | ------------------------------------------------------------ |
| `train_dir`                    | Dataset flag   | string | /tmp/yt8m_model/ | The directory to save the model files in.                    |
| `train_data_pattern`           | Dataset flag   | string | NULL             | File glob for the training dataset. If the files refer to Frame Level features (i.e. tensorflow.SequenceExample), then set --reader_type format. The (Sequence)Examples are expected to have 'rgb' byte array sequence feature as well as a 'labels' int64 context feature. |
| `feature_names`                | Dataset flag   | string | mean_rgb         | Name of the feature to use for training.                     |
| `feature_sizes`                | Dataset flag   | string | 1024             | Length of the feature vectors.                               |
| `frame_features`               | Model flags    | bool   | False            | If set, then --train_data_pattern must be frame-level features. Otherwise, --train_data_pattern must be aggregated video-level features. The model must also be set appropriately (i.e. to read 3D batches VS 4D batches. |
| `model`                        | Model flags    | string | LogisticModel    | Which architecture to use for the model. Models are defined in models.py. |
| `start_new_model`              | Model flags    | bool   | False            | If set, this will not resume from a checkpoint and will instead create a new model instance. |
| `num_gpu`                      | Training flags | int    | 1                | The maximum number of GPU devices to use for training. Flag only applies if GPUs are installed |
| `batch_size`                   | Training flags | int    | 1024             | How many examples to process per batch for training.         |
| `label_loss`                   | Training flags | string | CrossEntropyLoss | Which loss function to use for training the model.           |
| `regularization_penalty`       | Training flags | float  | 1.0              | How much weight to give to the regularization loss (the label loss has a weight of 1). |
| `base_learning_rate`           | Training flags | float  | 0.01             | Which learning rate to start with.                           |
| `learning_rate_decay`          | Training flags | float  | 0.95             | Learning rate decay factor to be applied every learning_rate_decay_examples. |
| `learning_rate_decay_examples` | Training flags | float  | 4000000          | Multiply current learning rate by learning_rate_decay every learning_rate_decay_examples. |
| `num_epochs`                   | Training flags | int    | 5                | How many passes to make over the dataset before halting training. |
| `max_steps`                    | Training flags | int    | None             | The maximum number of iterations of the training loop.       |
| `export_model_steps`           | Training flags | int    | 1000             | The period, in number of steps, with which the model is exported for batch prediction. |
| `num_readers`                  | Other flags    | int    | 8                | How many threads to use for reading input files.             |
| `optimizer`                    | Other flags    | string | AdamOptimizer    | What optimizer class to use.                                 |
| `clip_gradient_norm`           | Other flags    | float  | 1.0              | Norm to clip gradients to.                                   |
| `log_device_placement`         | Other flags    | bool   | False            | Whether to write the device on which every op will run into the logs on startup. |



## Mixture of Experts (MoE)

The idea is to train many NN to have a group such that each of them specializes in a different part of the data. That is if we assume that a dataset comes from a number of different regimes and we train a system in which one NN will specialize in one of the regimes and manager NN will look at the input data and assign a specific (specialized) NN for that computation.   

> **Note**: This kind of system doesn't make very efficient use of the data as the data is fractionated over all these different experts. So with small datasets, we can't expect to do very well. On the other hand, this is very good for very large datasets. 

In `boosting`, the weights on the model are not all equal, but after we finish training, each model has the same weight for each test case. We don't make the weights of individual model depend on which particular case we're dealing with. In `MoE` we do ! 

>**Idea** : We can look at the input data for the particular case (during both training and testing) to help us decide on which model we can rely on. During training, this will allow models to specialize on a subset of the cases. They **do not learn** on the cases for which they are not picked. This will lead to a model that is very good at something but very bad at other things. 

The key idea is to make each expert focus on predicting the right answer for the cases where it is already doing better than the other experts. 

