NN_FILENAME=$1
NN_NEW_FILENAME=$2
ACTIVATION=$3
L_TARGET=$4
REGRESSION_ERROR_BOUND=$5
SCALAR=$6
OFFSET=$7

python approx.py --filename $NN_FILENAME --original_activation $ACTIVATION --input_dim 2 --output_dim 1 --max_it 10000 --output_file $NN_NEW_FILENAME --Lipschitz $L_TARGET --range 1.5 --activation $ACTIVATION --scalar $SCALAR --ua_scalar $SCALAR --offset $OFFSET --ua_offset $OFFSET --stepsize 1e-3 --regression_bound $REGRESSION_ERROR_BOUND
