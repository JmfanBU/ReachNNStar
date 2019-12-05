cd ReachNN/flowstar/ &&\
make &&\
cd ../Bernstein_Polynomial_Approximation/ &&\
g++ -c bernstein_poly_approx.cpp -I/usr/include/python3.6m/ -lpython3.6m &&\
ar -cr libbernstein_poly_approx.a bernstein_poly_approx.o
