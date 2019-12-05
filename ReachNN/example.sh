NNCS=$1
ERROR=$2

cd Bernstein_Polynomial_Approximation &&\
make name=$NNCS &&\
python error_analysis.py --filename $NNCS --error_bound $ERROR
