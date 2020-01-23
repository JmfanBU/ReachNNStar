# ReachNN*
ReachNN* is a reachability analysis approach based on Bernstein
polynomials that can verify neural-network controlled systems (NNCSs)
with a more general form of activation functions. We further explore how
certain property, like Lipschitz constant, of the network influences the
verification result and propose a new Verification-aware Knowledge
Distillation method to distill a new neural network controller that is
more verification-friendly and retain the knowledge from the orignal
nerual network controller.

ReachNN* is a GPU implementation of the original proposed ReachNN tool
and integrate the function of Verification-aware Knwoledge
Distillation. We achieved at least 3X faster verification running time
compared to the original ReachNN tool.

## Execution on VM

ReachNN* can be tested in [Virtual
Machine](https://drive.google.com/file/d/1PzHcbV8QnmqksN180BWLgcH04wQB_Tf9/view?usp=sharing), please download it and
import the .ova file using Oracle VM Virtual Box.

## Installation

#### System Requirements
Ubuntu 18.04, Python 3.6

#### Up-to-date Installation
- Install dependencies through apt-get install
```
sudo apt-get install m4 libgmp3-dev libmpfr-dev libmpfr-doc libgsl-dev gsl-bin bison flex gnuplot-x11 libglpk-dev gcc-8 g++-8 libopenmpi-dev
```
- Install python libraries
```
sudo apt-get install python3-pip

sudo pip3 install -U virtualenv

virtualenv --system-site-packages -p python3 ~/venv

source ~/venv/bin/activate

pip install pip --upgrade

pip install tensorflow==1.15.0 # or tensorflow-gpu, tensoflow 2.0 has not been tested.

pip install sympy mpi4py scipy h5py

```


#### Compile Flow* and ReachNN

```

./compile.sh # under the root directory ./ReachNNStar/

```

## Runing Example

NOTE: All the capitalized word is the input argument and have no suffix.

Please activate the python virtualenv before running any examples

```

source ~/venv/bin/activate

```

### Reachability Analysis for NNCS

#### This will replicate the experiments results from #1 to #5.

```

cd ReachNN

./run_exp.sh

```

The results will return to ReachNNTool/ReachNN/outputs. To check the results, run the following code

```

vim FILENAME.txt

gnuplot FILENAME.plt

cd images

```

The ploted result will be in images folder with the same filename as the example.

#### Run individual results
Please refer to the template in run_exp.sh

The NN description file is in ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/nn

The cpp file should be saved in ReachNNTool/ReachNN/Bernstein_Polynomial_Approximation/systems

```

./example.sh FILENAME ERROR_BOUND # FILENAME is the example's cpp filename; ERROR_BOUND depends on the system's sensitivity

```

### Verification-Aware Knowledge Distillation

#### This will replicate the running example
```

cd VF_Retraining

./run_distillation

```
Please check the result in ReachNNTool/ReachNN/outputs/nn_13_relu_tanh_*

The one with origin as suffix is the result of original NN.

The one with 1 as suffix is the result of the distilled NN.

#### Run Individual Task
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

## Contributors
[Jiameng Fan](https://www.jiamengf.com), [Chao Huang](https://chaohuang2018.github.io/main/), [Wenchao Li](http://sites.bu.edu/depend/people/), [Xin Chen](https://udayton.edu/directory/artssciences/computerscience/chen-xin.php), [Qi Zhu](http://users.eecs.northwestern.edu/~qzhu/)

## References
C.Huang, J.Fan, W.Li, X.Chen, and Q.Zhu.
[Reachnn: Reachabilityanalysisofneural-network controlled systems](https://dl.acm.org/citation.cfm?id=3358228).
ACM Transactions on Embedded Computing Systems, 18:1–22, 10 2019. doi: 10.1145/3358228.

J.Fan, C.Huang, W.Li, X.Chen, and Q.Zhu.
[Towards Verification-Aware Knowledge Distillation for Neural-Network Controlled Systems](https://ieeexplore.ieee.org/abstract/document/8942059).
International Conference on Computer Aided Design (ICCAD), November 2019.

## Common Issues
### m4: unrecognized option '--gnu'
To fix this problem, try to reinstall m4 first
```
sudo apt-get install --reinstall m4
```

