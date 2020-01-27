# Example 6
./example.sh nn_tora_relu 1e-2 &&\
./example.sh nn_tora_sigmoid 1e-2 &&\
./example.sh nn_tora_tanh 1e-2 &&\
./example.sh nn_tora_relu_tanh 1e-2 &&\

# Generate Plot
cd outputs &&\
gnuplot *.plt
