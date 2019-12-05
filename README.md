# ReachNN*

## Installation

### Install Dependencies

```
cd packages

sudo dpkg -i *.deb

cd python

sudo pip3 install -U virtualenv/virtualenv-16.7.7-py2.py3-none-any.whl

virtualenv --system-site-packages -p python3 ~/venv

source ~/venv/bin/activate

pip install pip/pip-19.3.1-py2.py3-none-any.whl

cd tensorflow

pip install *.gz

pip install *.whl
 
cd ../sympy

pip install *.gz

pip install *.whl 

cd ..

pip install mpi4py/mpi4py-3.0.2.tar.gz

pip install scipy/scipy-1.3.1-cp36-cp36m-manylinux1_x86_64.whl

pip install h5py/h5py-2.10.0-cp36-cp36m-manylinux1_x86_64.whl 


```

### Compile

```

./compile.sh # under ReachNNTool directories

```

### Runing Example

NOTE: All the capitalized word is the input argument and have no suffix.

Please activate the python virtualenv before running any examples

```

source ~/venv/bin/activate

```

#### Reachability Analysis for NNCS

##### This will replicate the experiments results from #1 to #5.

```

cd ReachNN

./run_exp.sh

```

The results will return to ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/outputs. To check the results, run the following code

```

vim FILENAME.txt

gnuplot FILENAME.plt

cd images

```

The ploted result will be in images folder with the same filename as the example.

##### Run individual results
Please refer to the template in run_exp.sh

The NN description file is in ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/nn

The cpp file should be saved in ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/systems

```

./example.sh FILENAME ERROR_BOUND # FILENAME is the example's cpp filename; ERROR_BOUND depends on the system's sensiticity

```

#### Knowledge Distillation

##### This will replicate the running example
```

cd VF_Retraining

./run_knowledge_distillation

```
Please check the result in ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/outputs/nn_13_relu_tanh_*

The one with origin as suffix is the result of original NN.

The one with 1 as suffix is the result of the distilled NN.

##### Run Individual Task
```

cd VF_Retraining

cp NNFILE nn

./example.sh NN_FILENAME NN_NEW_FILENAME L_TARGET REGRESSION_ERROR_BOUND

```

The NN_NEW_FILENAME will be shown in nn_retrained. You should also add the offset and scalar at the last two lines in NN_NEW_FILENAME, which should be the same as the last two lines in NN_FILENAME.

After distillation, to rerun the reachability analysis on the new NN, execute the following commands:

```

cp nn_retrained/NN_NEW_FILENAME ../ReachNN/Bernstein_Polynomial_Approximation/nn

cd ../ReachNN/Bernstein_Polynomial_Approximation/systems

cp NN_FILENAME.cpp NN_NEW_FILENAME.cpp

vim NN_NEW_FILENAME.cpp # change the network name to NN_NEW_FILENAME in the cpp file and change the output file name to NN_NEW_FILENAME too.

cd ../../

./example.sh NN_NEW_FILENAME ERROR_BOUND

```

### Checking Result

All results will be stored in ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/outputs

Check the result with FILENAME

```

vim FILENAME.txt

gnuplot FILENAME.plt

```

Check the figures in outputs/images
