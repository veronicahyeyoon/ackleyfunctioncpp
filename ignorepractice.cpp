#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

//struct definition
struct struct_computed_xyz_value_storage {double final_x_coordinate_value, final_y_coordinate_value, z_ackley_result;};
std::random_device rd;
std::mt19937 gen(rd());

double random_coordinates_generator() {
    //this part generates random x and y
    std::uniform_real_distribution<double> random_big_dist(0.0, 10.0);
    double number_randomly_generated = random_big_dist(gen);

    //this part generates random small x and y that will be added to OG x and y
    //std::uniform_real_distribution<double> random_small_dist_to_be_added_to_x(-1.0, +1.0);
    //double add_to_x = random_small_dist_to_be_added_to_x(gen);

    //std::cout << "this is the randomly generated add_to_x: " << add_to_x << std::endl;
    //std::cout << "this is the randomly generated add_to_y: " << add_to_y << std::endl;
    
    //double new_x_for_ackleyfunction = random_x_value_storage[0]+ add_to_x;

    std::cout << "this is the randomly generated final number: " << number_randomly_generated << std::endl;

    return number_randomly_generated;
}

double random_add_to_coordinates_generator() {
    //this part generates random x and y
    std::uniform_real_distribution<double> random_big_dist(-1.0, +1.0);
    double add_to_number_randomly_generated = random_big_dist(gen);

    //this part generates random small x and y that will be added to OG x and y
    //std::uniform_real_distribution<double> random_small_dist_to_be_added_to_y(-1.0, +1.0);
    //double add_to_y = random_small_dist_to_be_added_to_y(gen);

    //std::cout << "this is the randomly generated add_to_x: " << add_to_x << std::endl;
    //std::cout << "this is the randomly generated add_to_y: " << add_to_y << std::endl;
    
    std::cout << "this is the randomly generated final add_to_number: " << add_to_number_randomly_generated << std::endl;

    return add_to_number_randomly_generated;
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
    //std::vector<double> vector_computed_xyz_value_storage;
    //struct_computed_xyz_value_storage global_minimum_coordinate;
    //bool is_this_global_minimum_z_value = false;
    struct_computed_xyz_value_storage best_coordinate_choice_so_far;
    struct_computed_xyz_value_storage candidate_coordinates;
    std::ofstream saved_xyz_file("saved_xyz_coordinates.txt", std::ios::app);
    bool is_this_best_coordinate_choice = false;

    for (int iteration = 0; iteration < 5; iteration++) {
        double random_x_result = random_coordinates_generator();
        double random_y_result = random_coordinates_generator();
        double random_add_to_x_result = random_add_to_coordinates_generator();
        double random_add_to_y_result = random_add_to_coordinates_generator();
        double final_x_coordinate_value = random_x_result + random_add_to_x_result;
        double final_y_coordinate_value = random_y_result + random_add_to_y_result;
        double z_ackley_result = ackleyfunctioncalculator(final_x_coordinate_value, final_y_coordinate_value);
        std::cout << "this is the final z result: " << z_ackley_result << std::endl;

        candidate_coordinates.final_x_coordinate_value = final_x_coordinate_value;
        candidate_coordinates.final_y_coordinate_value = final_y_coordinate_value;
        candidate_coordinates.z_ackley_result = z_ackley_result;

        if (!is_this_best_coordinate_choice || candidate_coordinates.z_ackley_result < best_coordinate_choice_so_far.z_ackley_result) {
            best_coordinate_choice_so_far = candidate_coordinates;
            is_this_best_coordinate_choice = true;
            std::cout << "z value updated to: " << candidate_coordinates.z_ackley_result << "\n";
        }
        else {
            std::cout << "point not small enough :0 " << candidate_coordinates.z_ackley_result << "\n"; 
        }
    }
    
    for (int iteration = 0; iteration < 50; iteration++) {

        for (int iter = 0; iter < 5; iter++) {
            double new_add_to_x_result = random_add_to_coordinates_generator();
            double new_add_to_y_result = random_add_to_coordinates_generator();

            double new_final_x_coordinate_value = best_coordinate_choice_so_far.final_x_coordinate_value + new_add_to_x_result;
            double new_final_y_coordinate_value = best_coordinate_choice_so_far.final_y_coordinate_value + new_add_to_y_result;

            double new_z_ackley_result = ackleyfunctioncalculator(new_final_x_coordinate_value, new_final_y_coordinate_value);

            if (new_z_ackley_result < best_coordinate_choice_so_far.z_ackley_result) {
                best_coordinate_choice_so_far.final_x_coordinate_value = new_final_x_coordinate_value;
                best_coordinate_choice_so_far.final_y_coordinate_value = new_final_y_coordinate_value;
                best_coordinate_choice_so_far.z_ackley_result = new_z_ackley_result;
                std::cout << "coordinates updated to: " << new_final_x_coordinate_value << " , " << new_final_y_coordinate_value << " ," << new_z_ackley_result << "\n";
            }
            else {
                std::cout << "coordinates not updated :0 " << "\n";
            }

        }

        saved_xyz_file << iteration << " "
                        << best_coordinate_choice_so_far.final_x_coordinate_value << " "
                        << best_coordinate_choice_so_far.final_y_coordinate_value << " "
                        << best_coordinate_choice_so_far.z_ackley_result << "\n";
    
    }
    saved_xyz_file.close();

    std::cout << "this is the final smallest number in the z value vector: " << best_coordinate_choice_so_far.z_ackley_result << "\n";
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