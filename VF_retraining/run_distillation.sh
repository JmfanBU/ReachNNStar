# Example 1 KD tanh
./example.sh nn_1_tanh nn_1_tanh_retrained TANH 0 4e-1 4 0 &&\
# Example 2 KD tanh
./example.sh nn_2_tanh nn_2_tanh_retrained TANH 0 2e-1 4 0 &&\
# Example 6 KD, this example have different input dimension and sampling range, so example_dim_range.sh is used here.
./example_dim_range.sh nn_tora_relu nn_tora_relu_retrained RELU 0 4e-1 1 10 4 1.5 &&\
./example_dim_range.sh nn_tora_relu_tanh nn_tora_relu_tanh_retrained RELU_TANH 0 4e-1 11 0 4 1.5 &&\

# copy networks to reachability analysis module and rerun rechability analysis
cp nn_retrained/* ../ReachNN/Bernstein_Polynomial_Approximation/nn/ &&\
cd ../ReachNN/ &&\
./example.sh nn_1_tanh_retrained 5e-3 &&\
./example.sh nn_2_tanh_retrained 1e-2 &&\
./example.sh nn_tora_relu_retrained 1e-2 &&\
./example.sh nn_tora_relu_tanh_retrained 1e-2

# Generate Plot
cd outputs &&\
gnuplot *.plt
