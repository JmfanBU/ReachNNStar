NN_FILENAME=$1
NN_NEW_FILENAME=$2
ACTIVATION=$3
L_TARGET=$4
REGRESSION_ERROR_BOUND=$5

python approx.py --filename $NN_FILENAME --original_activation $ACTIVATION --input_dim 2 --output_dim 1 --max_it 10000 --output_file $NN_NEW_FILENAME --Lipschitz $L_TARGET --range 1.2 --activation $ACTIVATION --scalar 4 --ua_scalar 4 --stepsize 1e-3 --regression_bound $REGRESSION_ERROR_BOUND
