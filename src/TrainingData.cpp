#include "TrainingData.h"
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::set;


TrainingData::TrainingData(const string& file_name) {

    string text_string = training_file_txt(file_name);
    set<char> uniqe_chars = chars_in_text(text_string);
    this->training_string = text_string;

}


string TrainingData::training_file_txt(string file_name) {
    

    string training_string;
    std::ifstream training_file;
    training_file.open(file_name);

    if (!training_file.is_open()){

        throw std::runtime_error ("Error: the file containing the training data couldn't be opened.");
             
        
        }
    
    string line;

    while(std::getline(training_file, line)){

        training_string += line;
    }

    if(training_string.empty()) {

        throw std::runtime_error ("Error: the file containing the training data is empty.");

    }

    return training_string;
}

set<char> TrainingData::chars_in_text(string text_string) {
        
        set<char> unique_chars(text_string.begin(), text_string.end());
        return unique_chars;
    }


string TrainingData::get_training_data() const {
    return training_string;
}













