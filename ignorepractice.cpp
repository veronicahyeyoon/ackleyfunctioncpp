#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>


double ackleyfunctioncalculator() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> random_big_dist(0.0, 10.0);
    double x = random_big_dist(gen);
    double y = random_big_dist(gen);
    std::vector<double> random_x_y_value_storage;
    random_x_y_value_storage.push_back(x);
    random_x_y_value_storage.push_back(y);
    
    /*
    this for loop gives the vector (what's in it at this point???)
    for (int i = 0; i < random_x_y_value_storage.size(); i++) {
        std::cout << random_x_y_value_storage[i]<< " ";
    }
    std::cout << "this is the randomly generated x: " << x << std::endl;
    std::cout << "this is the randomly generated y: " << y << std::endl;
    */

    double a= -0.2*(sqrt((x*x+y*y)/2));
    double b= (std::cos(2*std::acos(-1)*x)+std::cos(2*std::acos(-1)*y))/2;
    double z = -20*std::exp(a)-std::exp(b)+20+std::exp(1);

    std::uniform_real_distribution<double> random_small_dist_to_be_added(-1.0, +1.0);
    double add_to_x = random_small_dist_to_be_added(gen);
    double add_to_y = random_small_dist_to_be_added(gen);

    //std::cout << "this is the randomly generated add_to_x: " << add_to_x << std::endl;
    //std::cout << "this is the randomly generated add_to_y: " << add_to_y << std::endl;
    
    double new_x = random_x_y_value_storage[0]+ add_to_x;
    double new_y = random_x_y_value_storage[1] + add_to_y;

    std::cout << "this is the randomly generated final x value: " << new_x << std::endl;
    std::cout << "this is the randomly generated final y value: " << new_y << std::endl;

    return z;
}

int main() {

    std::vector<double> computed_z_value_storage;
    double previous_smallest_z;
    double smallestIndex = 0;

    for (int j = 0; j < 5; j++) {
        double result = ackleyfunctioncalculator();
        std::cout << "this is the result: "<< result << std::endl;
        computed_z_value_storage.push_back(result);

        for (int k = 1; k < computed_z_value_storage.size(); k++) {
        if (computed_z_value_storage[i] < computed_z_value_storage[smallestIndex]) {
            smallestIndex = k;
        }

        std::ofstream saved_xyz_file("saved_xyz_coordinates.txt", std::ios::app);
        
        double x_coordinate_for_txt_file = //placeholder
        //double y_coordinate_for_txt_file = //placeholder
        double z_coordinate_for_txt_file = smallestIndex;
        saved_xyz_file << x_coordinate_for_txt_file << " " << y_coordinate_for_txt_file << " " << z_coordinate_for_txt_file << " " <<std::endl;
        saved_xyz_file.close();

    }    
    }

    std::cout << "this is the final smallest number in the z value vector: " << computed_z_value_storage[smallestIndex] << std:: endl;
    std::cout << "file successfully saved: " << std::endl;
    /*
    for (int i = 0; i < computed_z_value_storage.size(); i++)
    {
        
        std::cout << computed_z_value_storage[i]<< " ";
    }
    
    */

    /*
    for (double j : computed_z_value_storage) {
            if (j < previous_smallest_z) {
                previous_smallest_z *= j;
                std::cout << "this is the new smallest z: " << j 
            }
            else {
                std::cout << "point not small enough :(" << std::endl;
            }

        }
    */

}