#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdexcept>

#include "SmallLanguageModel.h"
#include "TrainingData.h"
#include "TextGenerator.h"

using std::string;


int main(int argc, char *argv[]) {

    string input_file;
    int kgram;
    double alpha=0.0;
    int w;

    try{

        if (argc != 4 && argc != 6){

            throw std::invalid_argument("slm: wrong number of arguments.");
        }

        if (argc == 4){
        
            try{
                kgram = std::stoi(argv[1]);
                w=std::stoi(argv[3]);
                input_file = argv[2];
            }
            catch(...){
                throw std::invalid_argument("slm: invalid argument input.");
            }
        }

        if (argc==6){

            string a="-a";
            if(string(argv[1])!=a){
                throw std::invalid_argument("slm: unknown argument '"+string(argv[1])+"'.");
            }

            try{

                kgram = std::stoi(argv[3]);
                w=std::stoi(argv[5]);
                input_file = argv[4];
                alpha = std::stod(argv[2]);
            }
            catch(...){
                throw std::invalid_argument("slm: invalid argument input.");
            }

            if (alpha<0)
            {
                throw std::invalid_argument("slm: the pseudocount cannot be negative.");
            }
        }

        if(kgram<=0){
            throw std::invalid_argument("slm: 'k' must be a positive integer.");
        }

        if(w<kgram){
            throw std::invalid_argument("slm: the output length 'w' must be greater than or equal to 'k'.");
        }
    

        TrainingData TrainingData(input_file);
        SmallLanguageModel SmallLanguageModel(kgram, alpha);
        TextGenerator TextGenerator(w, kgram);

        auto training_string = TrainingData.get_training_data();
        auto uniqe_chars = TrainingData.get_uniqe_chars();

        auto kgram_map = SmallLanguageModel.kgram_function(training_string);

        auto complete_map = SmallLanguageModel.complete_kgram_char_map(kgram_map, training_string, uniqe_chars);

        auto generated_text = TextGenerator.generator(kgram_map, complete_map);

        TextGenerator.output_text_func(generated_text);


    }

    catch (const std::exception& e){

        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
