#ifndef TrainingData_h
#define TrainingData_h

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class TrainingData {

    private:

        string training_file_txt (std::string file_name);

        string training_string;

    public:

        TrainingData(const std::string& file_name);

        std::string get_training_data() const;
        

};




#endif












