#ifndef TrainingData_h
#define TrainingData_h

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::string;
using std::set;

class TrainingData {

    private:

        string training_file_txt (string file_name);

        string training_string;

        set<char> chars_in_text (string string);

    public:

        TrainingData(const string& file_name);

        string get_training_data() const;
        

};




#endif












