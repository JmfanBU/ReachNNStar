# Example Usage (Example 1)
./example.sh nn_1_relu_tanh_origin nn_1_relu_tanh_retrained RELU_TANH 0 4e-1 4 0 &&\
cp nn_retrained/* ../ReachNN/Bernstein_Polynomial_Approximation/nn/ &&\
cd ../ReachNN/ &&\
./example.sh nn_1_relu_tanh_retrained 5e-3
