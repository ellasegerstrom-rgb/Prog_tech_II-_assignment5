#include "TrainingData.h"
#include <iostream>
#include <string>
#include <fstream>

std::string TrainingData::training_file_txt(const std::string& file_name) {
    
    std::string training_text;
    std::ifstream training_file;
    training_file.open(file_name);

    if (!training_file.is_open()){

        throw std::runtime_error ("Error: the file containing the training data couldn't be opened.");
             
        
        }
    
    std::string line;

    while(std::getline(training_file, line)){

        training_text += line;
    }

    if(training_text.empty()) {

        throw std::runtime_error ("Error: the file containing the training data is empty.");

    }

}











