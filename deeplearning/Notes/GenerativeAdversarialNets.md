

### Overview

Ian starts with talking about the recent things happening in machine learning. He pointed that discriminated learnings are now really hot and mature. backprop algorithms and drop out methods are studied extensively and now well understood. He starts with `Defining the Problem` of having less impact of deep discriminating algorithms. He says, this happens because of two reasons : it really difficult to approximate the  intractable probabilistic computations that arises maximum likelihood and it is also difficult to leverage the benefits of piecewise linear units in the generative context. 

> **Note** : No approximate inference or markov chains are necessary in his algorithm.

### Generative modeling and related work

How the generative models have developed? Usually, all of the known generative techniques focus on a model that provides the parameterized specification of a probability distribution function. Now what the hell  is that?! all it means is we are trying to find the parameters of that probability distribution that explains the current distribution. `Deep Boltzmann machines`, he mentions to be the best. Problem with this : intractable MLE gradient ! what do we do? `Generative stochastic networks` is one of the 
"generative machines" - (models that do not explicitly represents MLE) that can be used without any gradient approximations. 

**How GAN and VAE are different?**  Unlike generative adversarial networks, the second
network in a VAE is a recognition model that performs approximate inference. GANs require
differentiation through the visible units, and thus cannot model discrete data, while VAEs require
differentiation through the hidden units, and thus cannot have discrete latent variables.

TODO : **READ ABOUT NCE and then compare**

TODO : Read Geoff Hiltons paper on dropout stuff and answer the question. What is this? Why do we need predictably minimization? How predictably minimization is different from this work. 

### BUILDING ADVERSARIAL NETS 

The overall idea is to generate a distribution $p_g$ from a user defined distribution (a.k.a prior distribution) $p_z$. The function that we use to generate this $p_g$ is $G(z|\theta_g)$, which is our neural net - "generator". We also need a discriminator neural net $D(x|\theta_d)$ which takes $x$ and spills out a probability that $x$ came from $p_{data}$ not from $p_g$. 

We train $D$ to maximize the probability of assigning the correct label and train $G$ to minimize $\log(1-D(G(z)))$  



### Understanding the the value function

After theoretical proof, Ian shows that the value function actually determines the the divergence between the two probability distribution given that the discriminator is optimal. 

 