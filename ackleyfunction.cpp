//some sort of description
//required imports here
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

//some definitions
struct struct_computed_xyz_value_storage {double final_x_coordinate_value, final_y_coordinate_value, z_ackley_result;};
std::random_device rd;
std::mt19937 gen(rd());
std::string how_do_you_do;

//function for generating random coordinates
double random_coordinates_generator() {

    std::uniform_real_distribution<double> random_big_dist(0.0, 10.0);
    double number_randomly_generated = random_big_dist(gen);
    //std::cout << "this is the randomly generated final number: " << number_randomly_generated << "\n";

    return number_randomly_generated;
}

//function for generating random small coordinates to be added to coordinates
double random_add_to_coordinates_generator() {

    std::uniform_real_distribution<double> random_big_dist(-1.0, +1.0);
    double add_to_number_randomly_generated = random_big_dist(gen);
    //std::cout << "this is the randomly generated final add_to_number: " << add_to_number_randomly_generated << "\n";

    return add_to_number_randomly_generated;
}

//function that calculates z_value via the Ackley function
double ackleyfunctioncalculator(double new_x_for_ackleyfunction, double new_y_for_ackleyfunction) {

    double a= -0.2*(sqrt((new_x_for_ackleyfunction*new_x_for_ackleyfunction+new_y_for_ackleyfunction*new_y_for_ackleyfunction)/2));
    double b= (std::cos(2*std::acos(-1)*new_x_for_ackleyfunction)+std::cos(2*std::acos(-1)*new_y_for_ackleyfunction))/2;
    double z = -20*std::exp(a)-std::exp(b)+20+std::exp(1);

    return z;
}

//main function running everything & generating txt file
int main() {

    struct_computed_xyz_value_storage best_coordinate_choice_so_far;
    std::ofstream saved_xyz_file("saved_xyz_coordinates.txt", std::ios::app);

    std::cout << "Hello, I am an Ackley function minimizer" "\n";
    std::cout << "First, how are you?" "\n";
    std::cin >> how_do_you_do;
    std::cout << "Thanks for answering " << how_do_you_do<< std::endl;
    std::cout << "Now let's actually begin :)" "\n";

    double random_x_result = random_coordinates_generator();
    double random_y_result = random_coordinates_generator();
    double random_add_to_x_result = random_add_to_coordinates_generator();
    double random_add_to_y_result = random_add_to_coordinates_generator();
    double final_x_coordinate_value = random_x_result + random_add_to_x_result;
    double final_y_coordinate_value = random_y_result + random_add_to_y_result;
    double z_ackley_result = ackleyfunctioncalculator(final_x_coordinate_value, final_y_coordinate_value);
    best_coordinate_choice_so_far.final_x_coordinate_value = final_x_coordinate_value;
    best_coordinate_choice_so_far.final_y_coordinate_value = final_y_coordinate_value;
    best_coordinate_choice_so_far.z_ackley_result = z_ackley_result;
    saved_xyz_file << best_coordinate_choice_so_far.final_x_coordinate_value << " " 
                    << best_coordinate_choice_so_far.final_y_coordinate_value << " " 
                    << best_coordinate_choice_so_far.z_ackley_result << " " << "\n";

    std::cout << "this is the first coordinate's z value: " << z_ackley_result << "\n";
    
    
    for (int iteration = 0; iteration < 250; iteration++) {
        struct_computed_xyz_value_storage iteration_best_coordinate_so_far;
        bool is_this_best_coordinate_so_far = false;
        
        for (int iter = 0; iter < 5; iter++) {
            double new_add_to_x_result = random_add_to_coordinates_generator();
            double new_add_to_y_result = random_add_to_coordinates_generator();

            double new_final_x_coordinate_value = best_coordinate_choice_so_far.final_x_coordinate_value + new_add_to_x_result;
            double new_final_y_coordinate_value = best_coordinate_choice_so_far.final_y_coordinate_value + new_add_to_y_result;
            double new_z_ackley_result = ackleyfunctioncalculator(new_final_x_coordinate_value, new_final_y_coordinate_value);

            struct_computed_xyz_value_storage children_coordinates;
            children_coordinates.final_x_coordinate_value = new_final_x_coordinate_value;
            children_coordinates.final_y_coordinate_value = new_final_y_coordinate_value;
            children_coordinates.z_ackley_result = new_z_ackley_result;

            if (!is_this_best_coordinate_so_far || children_coordinates.z_ackley_result < iteration_best_coordinate_so_far.z_ackley_result) {
                iteration_best_coordinate_so_far = children_coordinates;
                is_this_best_coordinate_so_far = true;
            }
            

    }
        best_coordinate_choice_so_far = iteration_best_coordinate_so_far;

        saved_xyz_file << best_coordinate_choice_so_far.final_x_coordinate_value << " "
                        << best_coordinate_choice_so_far.final_y_coordinate_value << " "
                        << best_coordinate_choice_so_far.z_ackley_result << "\n";
        std::cout << "coordinates updated to: " << best_coordinate_choice_so_far.final_x_coordinate_value << " , " << best_coordinate_choice_so_far.final_y_coordinate_value << " ," << best_coordinate_choice_so_far.z_ackley_result << "\n";
    
}
    saved_xyz_file.close();
    std::cout << "this is the final smallest number in the z value vector: " << best_coordinate_choice_so_far.z_ackley_result << "\n";
    std::cout << "file successfully saved :0 " << std::endl;


return 0;

}