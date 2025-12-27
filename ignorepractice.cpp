#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>


double ackleyfunctioncalculator() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> random_big_dist(0.0, 10.0);
    double x = random_big_dist(gen);
    double y = random_big_dist(gen);
    std::vector<double> random_x_y_value_storage;
    random_x_y_value_storage.push_back(x);
    random_x_y_value_storage.push_back(y);
    for (int i = 0; i < random_x_y_value_storage.size(); i++) {
        std::cout << random_x_y_value_storage[i]<< " ";
    }
    //std::cout << "this is the randomly generated x: " << x << std::endl;
    //std::cout << "this is the randomly generated y: " << y << std::endl;

    double a= -0.2*(sqrt((x*x+y*y)/2));
    double b= (std::cos(2*std::acos(-1)*x)+std::cos(2*std::acos(1)*y))/2;
    double z = -20*std::exp(a)-std::exp(b)+20+std::exp(1);

    for (int i = 0; i < 5; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> random_small_dist_to_be_added(-1.0, +1.0);
        double add_to_x = random_small_dist_to_be_added(gen);
        double add_to_y = random_small_dist_to_be_added(gen);

        double new_x = x + add_to_x;
        double new_y = y + add_to_y;
    }

    return z;
}

int main() {
    std::vector<double> computed_z_value_storage;
    for (int i = 0; i < 5; i++) {
        double result = ackleyfunctioncalculator();
        std::cout << "this is the result: "<< result << std::endl;
        computed_z_value_storage.push_back(result);
    } 


    /*
    for (int i = 0; i < computed_z_value_storage.size(); i++)
    {
        
        std::cout << computed_z_value_storage[i]<< " ";
    }
     */

    return 0;

}