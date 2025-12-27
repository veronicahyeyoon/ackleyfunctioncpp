# video simulation for optimization (C++ version)

The Ackley function is a mathematical test function that is often used to test how well algorithms can find a global minima among many other local minima. This code is written in C++ and Python to help you visualize how an optimal minimum point can be found in an Ackley function in 3D.

The Ackley function can be represented as:

$f(x) = -a \exp(-b\sqrt(\frac{1}{n}\sum_{i=1}^d x_i^2))-\exp(\frac{1}{d}\sum_{i=1}^d \cos(cx_i))+a+\exp(1)$

where recommended parameters are __$a=20$__, __$b=0.2$__, and __$c=2\pi$__, which are what this code uses.