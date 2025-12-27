#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>


double ackleyfunctioncalculator()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 20.0);
    double j = dist(gen);
    double k = dist(gen);
    //std::vector<double> random_x_y_value_storage
    std::cout << "this is the randomly generated j: " << j << std::endl;
    std::cout << "this is the randomly generated k: " << k << std::endl;

    double a= -0.2*(sqrt((j*j+k*k)/2));
    double b= (std::cos(2*std::acos(-1)*j)+std::cos(2*std::acos(1)*k))/2;
    double z = -20*std::exp(a)-std::exp(b)+20+std::exp(1);

    return z;
}

int main()
{
    for (int i = 0; i < 5; i++) {
        double result = ackleyfunctioncalculator();
        std::vector<double> computed_z_value_storage;
        computed_z_value_storage.push_back(result);
    } 

    std::cout << "this is the result: "<< result << std::endl;

    /*
    for (int i = 0; i < computed_z_value_storage.size(); i++)
    {
        
        std::cout << computed_z_value_storage[i]<< " ";
    }
     */

    return 0;

}