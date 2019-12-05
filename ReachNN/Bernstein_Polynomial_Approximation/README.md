# Bernstein_Polynomial_Approximation

## Command for testing static library:
```
g++ -c bernstein_poly_approx.cpp -I/usr/include/python3.6m/ -lpython3.6m
ar -cr libbernstein_poly_approx.a bernstein_poly_approx.o
g++ test_a.cpp -o test_a libbernstein_poly_approx.a -I/usr/include/python3.6m/ -lpython3.6m
```

## Running example
```
python error_analysis.py --filename nn_13_sigmoid --error_bound 1e-3
```
