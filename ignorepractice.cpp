#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

//struct definition
struct struct_computed_xyz_value_storage {double random_x_loop_result, random_y_loop_result, z_ackley_result;};

double random_x_coordinates_generator() {
    //this part generates random x and y
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> random_big_dist(0.0, 10.0);
    double x_randomly_generated = random_big_dist(gen);

    std::vector<double> random_x_value_storage;
    random_x_value_storage.push_back(x_randomly_generated);
    //random_x_y_value_storage.push_back(y_randomly_generated);

    //this part generates random small x and y that will be added to OG x and y
    std::uniform_real_distribution<double> random_small_dist_to_be_added_to_x(-1.0, +1.0);
    double add_to_x = random_small_dist_to_be_added_to_x(gen);

    //std::cout << "this is the randomly generated add_to_x: " << add_to_x << std::endl;
    //std::cout << "this is the randomly generated add_to_y: " << add_to_y << std::endl;
    
    double new_x_for_ackleyfunction = random_x_value_storage[0]+ add_to_x;

    std::cout << "this is the randomly generated final x value: " << new_x_for_ackleyfunction << std::endl;

    return new_x_for_ackleyfunction;
}

double random_y_coordinates_generator() {
    //this part generates random x and y
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> random_big_dist(0.0, 10.0);
    double y_randomly_generated = random_big_dist(gen);

    std::vector<double> random_y_value_storage;
    random_y_value_storage.push_back(y_randomly_generated);

    //this part generates random small x and y that will be added to OG x and y
    std::uniform_real_distribution<double> random_small_dist_to_be_added_to_y(-1.0, +1.0);
    double add_to_y = random_small_dist_to_be_added_to_y(gen);

    //std::cout << "this is the randomly generated add_to_x: " << add_to_x << std::endl;
    //std::cout << "this is the randomly generated add_to_y: " << add_to_y << std::endl;
    
    double new_y_for_ackleyfunction = random_y_value_storage[0] + add_to_y;

    std::cout << "this is the randomly generated final y value: " << new_y_for_ackleyfunction << std::endl;

    return new_y_for_ackleyfunction;
}

double ackleyfunctioncalculator(double new_x_for_ackleyfunction, double new_y_for_ackleyfunction) {
    /*
    this for loop gives the vector (what's in it at this point???)
    for (int i = 0; i < random_x_y_value_storage.size(); i++) {
        std::cout << random_x_y_value_storage[i]<< " ";
    }
    std::cout << "this is the randomly generated x: " << x << std::endl;
    std::cout << "this is the randomly generated y: " << y << std::endl;
    */

    double a= -0.2*(sqrt((new_x_for_ackleyfunction*new_x_for_ackleyfunction+new_y_for_ackleyfunction*new_y_for_ackleyfunction)/2));
    double b= (std::cos(2*std::acos(-1)*new_x_for_ackleyfunction)+std::cos(2*std::acos(-1)*new_y_for_ackleyfunction))/2;
    double z = -20*std::exp(a)-std::exp(b)+20+std::exp(1);

    return z;
}

int main() {
    std::vector<struct_computed_xyz_value_storage> points;
    //std::vector<double> vector_computed_xyz_value_storage;
    double previous_smallest_z;
    int smallestIndex = 0;

    for (int i = 0; i < 5; i++) {
        double random_x_loop_result = random_x_coordinates_generator();
        double random_y_loop_result = random_y_coordinates_generator();
        //std::cout << "this is the x result: "<< random_x_loop_result << std::endl;
        //std::cout << "this is the y result: " << random_y_loop_result << std::endl;

        double z_ackley_result = ackleyfunctioncalculator(random_x_loop_result, random_y_loop_result);
        std::cout << "this is the final z result: " << z_ackley_result << std::endl;
        struct_computed_xyz_value_storage row;
        row.random_x_loop_result = random_x_loop_result;
        row.random_y_loop_result = random_y_loop_result;
        row.z_ackley_result = z_ackley_result;
        points.push_back(row);

    }
    
    for (int k = 0; k < points.size(); k++) {
        if (k == 0 || points[k].z_ackley_result < points[smallestIndex].z_ackley_result) {
            smallestIndex = k;
            std::cout << "smallest point is: " << points[smallestIndex].z_ackley_result << "\n";
        }
        else {
            std::cout << "point not small enough :0" "\n";
        }

    }

    std::ofstream saved_xyz_file("saved_xyz_coordinates.txt", std::ios::app);
    double x_coordinate_for_txt_file = points[smallestIndex].random_x_loop_result;
    double y_coordinate_for_txt_file = points[smallestIndex].random_y_loop_result;
    double z_coordinate_for_txt_file = points[smallestIndex].z_ackley_result;
    saved_xyz_file << x_coordinate_for_txt_file << " " << y_coordinate_for_txt_file << " " << z_coordinate_for_txt_file << " " <<std::endl;
    saved_xyz_file.close();

    std::cout << "this is the final smallest number in the z value vector: " << points[smallestIndex].z_ackley_result << std:: endl;
    std::cout << "file successfully saved: " << std::endl;
    /*
    for (int i = 0; i < computed_z_value_storage.size(); i++)
    {
        
        std::cout << computed_z_value_storage[i]<< " ";
    }s
    
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