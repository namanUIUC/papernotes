# YOUTUBE - 8m

## Mixture of Experts (MoE)

The idea is to train many NN to have a group such that each of them specializes in a different part of the data. That is if we assume that a dataset comes from a number of different regimes and we train a system in which one NN will specialize in one of the regimes and manager NN will look at the input data and assign a specific (specialized) NN for that computation.   

> **Note**: This kind of system doesn't make very efficient use of the data as the data is fractionated over all these different experts. So with small datasets, we can't expect to do very well. On the other hand, this is very good for very large datasets. 

In `boosting`, the weights on the model are not all equal, but after we finish training, each model has the same weight for each test case. We don't make the weights of individual model depend on which particular case we're dealing with. In `MoE` we do ! 

> **Idea** : We can look at the input data for the particular case (during both training and testing) to help us decide on which model we can rely on. During training, this will allow models to specialize on a subset of the cases. They **do not learn** on the cases for which they are not picked. This will lead to a model that is very good at something but very bad at other things. 

The key idea is to make each expert focus on predicting the right answer for the cases where it is already doing better than the other experts. 