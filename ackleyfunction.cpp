//this code will give you a video simulation of how points on an ackley function are minimized. 

//required imports here
#include <iostream>
#include <string>
#include <vector>
#include <random>

//definitions before function
std::string throwaway;
double a, b, z;

//ackley function calculator
double ackleyfunctioncalculator()
{
    std::vector<double> ackleyfunction;
    ackleyfunction.push_back(1);
    ackleyfunction.push_back(2);
    ackleyfunction.push_back(5);

    return z;
}


int main() {
    std::cout << "Hello, I am an Ackley function minimizer" "\n";
    std::cout << "First, how are you?" "\n";
    std::cin >> throwaway;
    std::cout << "Thanks for answering " << throwaway << std::endl;
    std::cout << "Now let's actually begin :)" "\n";
    std::cout << "These are the random numbers generated " "\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 10.0);
    double a = dist(gen);
    std::cout << a << '\n';


    return 0;
}