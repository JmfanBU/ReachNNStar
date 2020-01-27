# Example Usage (Example 1)
./example.sh nn_1_tanh nn_1_tanh_retrained TANH 0 4e-1 4 0 &&\
./example.sh nn_2_tanh nn_2_tanh_retrained TANH 0 1e-1 4 0 &&\
./example.sh nn_3_relu_sigmoid nn_3_relu_sigmoid_retrained RELU_SIGMOID 0 1e-1 4 0.5 &&\
cp nn_retrained/* ../ReachNN/Bernstein_Polynomial_Approximation/nn/ &&\
cd ../ReachNN/ &&\
./example.sh nn_1_tanh_retrained 5e-3 &&\
./example.sh nn_2_tanh_retrained 1e-2 &&\
./example.sh nn_3_relu_sigmoid_retrained 5e-3
