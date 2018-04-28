### Creating a naive perceptron network

The following is the code for the simple perceptron:

```python
import tensorflow as tf

Input = tf.placeholder('float', shape=[None, 2], name="Input")
GT = tf.placeholder('float', shape=[None, 1], name="GT")
inputBias = tf.Variable(initial_value=tf.random_normal(shape=[3], stddev=0.4), dtype='float', name="input_bias")

weights = tf.Variable(initial_value=tf.random_normal(shape=[2, 3], stddev=0.4), dtype='float', name="hidden_weights")
hiddenBias = tf.Variable(initial_value=tf.random_normal(shape=[1], stddev=0.4), dtype='float', name="hidden_bias")
outputWeights = tf.Variable(initial_value=tf.random_normal(shape=[3, 1], stddev=0.4), dtype='float', name="output_weights")

hiddenLayer = tf.matmul(Input, weights) + inputBias
hiddenLayer = tf.sigmoid(hiddenLayer, name="hidden_layer_activation")

output = tf.matmul(hiddenLayer, outputWeights) + hiddenBias
output = tf.sigmoid(output, name="output_layer_activation")

cost = tf.reduce_mean(tf.squared_difference(GT, output))
optimizer = tf.train.AdamOptimizer().minimize(cost)

inp = [[1, 1], [1, 0], [0, 1], [0, 0]]
out = [[0], [1], [1], [0]]

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    for i in range(5000):
        cost_output, _ = sess.run([cost, optimizer], feed_dict={Input: inp, GT: out})


```

The above code will perform simple perceptron algorithm. 



### Tensorboard simple syntax

need to add these lines of codes where the graphs are initialized:

```python 
# Summary
tf.summary.histogram(name="w1", values=weights)
tf.summary.histogram(name="w2", values=outputWeights)
tf.summary.scalar("error", cost)
mergedSummary = tf.summary.merge_all()
```



Then we have to write it in the file as well. 

But this thing needs `sess` variable as the syntax. check out:

```python
filename = "./summary_log/run" + datetime.datetime.now().strftime("%Y-%m-%d--%H-%M-%s")
    writer = tf.summary.FileWriter(filename, sess.graph)
```

then we have to pass this `mergedSummary` variable for evaluation in the run session. 

So it looks like :

```python
    for i in range(5000):
        cost_output, _, sum_out = sess.run([cost, optimizer, mergedSummary], feed_dict={Input: inp, GT: out})
        writer.add_summary(sum_out, i)

```

### Running Tensorboard

This is the syntax for running it on the machine. Use the following terminal command: 

```ruby
tensorboard --logdir=./summary_log
```



### Refining the Tensorboard graph

Use of the following syntax to group things into cells:

```python
with tf.name_scope("Name") as scope:
```

the final code will be :

```python
import tensorflow as tf
import datetime

GT = tf.placeholder('float', shape=[None, 1], name="GT")

with tf.name_scope("Input_Layer") as scope:
    Input = tf.placeholder('float', shape=[None, 2], name="Input")
    inputBias = tf.Variable(initial_value=tf.random_normal(shape=[3], stddev=0.4), dtype='float', name="input_bias")

with tf.name_scope("Hidden_Layer") as scope:
    weights = tf.Variable(initial_value=tf.random_normal(shape=[2, 3], stddev=0.4), dtype='float', name="hidden_weights")
    hiddenBias = tf.Variable(initial_value=tf.random_normal(shape=[1], stddev=0.4), dtype='float', name="hidden_bias")
    hiddenLayer = tf.matmul(Input, weights) + inputBias
    hiddenLayer = tf.sigmoid(hiddenLayer, name="hidden_layer_activation")

with tf.name_scope("Output_Layer") as scope:
    outputWeights = tf.Variable(initial_value=tf.random_normal(shape=[3, 1], stddev=0.4), dtype='float', name="output_weights")
    output = tf.matmul(hiddenLayer, outputWeights) + hiddenBias
    output = tf.sigmoid(output, name="output_layer_activation")

with tf.name_scope("Optimizer_cell") as scope:
    cost = tf.reduce_mean(tf.squared_difference(GT, output))
    optimizer = tf.train.AdamOptimizer().minimize(cost)

inp = [[1, 1], [1, 0], [0, 1], [0, 0]]
out = [[0], [1], [1], [0]]

# Summary
tf.summary.histogram(name="w1", values=weights)
tf.summary.histogram(name="w2", values=outputWeights)
tf.summary.scalar("error", cost)
mergedSummary = tf.summary.merge_all()

with tf.Session() as sess:
    tf.global_variables_initializer().run()

    filename = "./summary_log/run" + datetime.datetime.now().strftime("%Y-%m-%d--%H-%M-%s")
    writer = tf.summary.FileWriter(filename, sess.graph)
    for i in range(5000):
        cost_output, _, sum_out = sess.run([cost, optimizer, mergedSummary], feed_dict={Input: inp, GT: out})
        writer.add_summary(sum_out, i)

```

