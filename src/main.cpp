#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdexcept>

#include "small_language_model.h"
#include "TrainingData.h"

int main(int argc, char* argv[]) {

    try {

        if (argc!=4 && argc!=6) {

            throw std::invalid_argument("Error: Invalid amount of arguments please enter $ slm <k-value> <training data> <output> or $ slm -a <pseudo-count> <k-value> <training data> <output>.");
        }
    
    
        if (argc == 4) {

            if (std::stoi(argv[1]) < 1) {
            
                throw std::invalid_argument("Error: Invalid k-value, the k-value must be a positive integer greater than 0.\n $slm <k-value> <training data> <output>");
            }

            if (std::stoi(argv[3])< std::stoi(argv[1])) {

                throw std::invalid_argument("Error: Invalid output length, the output lenght must be greater than or equal to the k-value.\n $slm <k-value> <training data> <output>" );
            }

        }

        if (argc == 6) {

             if (std::stoi(argv[3]) < 1) {
            
                throw std::invalid_argument("Error: Invalid k-value, the k-value must be a positive integer greater than 0.\n $slm -a <pseudo-count> <k-value> <training data> <output>");
            }

            if (std::stoi(argv[5])< std::stoi(argv[3])) {

                throw std::invalid_argument("Error: Invalid output length, the output lenght must be greater than or equal to the k-value.\n $slm -a <pseudo-count> <k-value> <training data> <output>" );
            }
            
            if (std::stoi(argv[2])<0){
                
                throw std::invalid_argument("Error: Invalid pseudo-count, the value must be an integer greater than or equal to 0.\n $slm -a <pseudo-count> <k-value> <training data> <output>");
            }

            std::string input_file = argv[4];

        } 

    }

    

    catch (const std::invalid_argument& e){

        std::cerr << e.what() << '\n';
        return 1;

    }


    std::string input_file;

    if(argc==4){
        input_file = argv[2];  
    }

    else if (argc==6){
        input_file = argv[4];
    }

    try{
        TrainingData training_data(input_file);
    }

    catch (const std::runtime_error& e){

        std::cerr << e.what() << '\n';
        return 1;

    }
    
}







