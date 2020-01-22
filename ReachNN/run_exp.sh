# Example 1
./example.sh nn_1_relu 1e-3 &&\
./example.sh nn_1_sigmoid 5e-3 &&\
./example.sh nn_1_tanh 5e-3 &&\
./example.sh nn_1_relu_tanh 5e-3 &&\

# Example 2
./example.sh nn_12_relu 1e-2 &&\
./example.sh nn_12_sigmoid 1e-3 &&\
./example.sh nn_12_tanh 1e-2 &&\
./example.sh nn_12_relu_tanh 1e-2 &&\

# Example 3
./example.sh nn_14_relu 1e-2 &&\
./example.sh nn_14_sigmoid 5e-3 &&\
./example.sh nn_14_tanh 1e-3 &&\
./example.sh nn_14_relu_sigmoid 5e-3 &&\

# Example 4
./example.sh nn_16_relu 5e-3 &&\
./example.sh nn_16_sigmoid 1e-2 &&\
./example.sh nn_16_tanh 1e-2 &&\
./example.sh nn_16_relu_tanh 1e-2 &&\

# Example 5
./example.sh nn_18_relu 4e-3 &&\
./example.sh nn_18_sigmoid 4e-3 &&\
./example.sh nn_18_tanh 4e-3 &&\
./example.sh nn_18_relu_tanh 4e-3 &&\

# Generate Plot
cd outputs &&\
gnuplot *.plt
