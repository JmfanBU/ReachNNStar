# Example ACC, this example have different input dimension and sampling range, so example_dim_range.sh is used here.
./example_ACC.sh ACC_5_20 ACC_KD_3 RELU 1 4e-1 1 0 5 150

# copy networks to reachability analysis module and rerun rechability analysis
# cp nn_retrained/* ../ReachNN/Bernstein_Polynomial_Approximation/nn/ &&\
# cd ../ReachNN/ &&\
# ./example.sh nn_1_tanh_retrained 5e-3 &&\
# ./example.sh nn_2_tanh_retrained 1e-2 &&\
# ./example.sh nn_tora_relu_retrained 1e-2 &&\
# ./example.sh nn_tora_relu_tanh_retrained 1e-2
# 
# # Generate Plot
# cd outputs &&\
# gnuplot *.plt
