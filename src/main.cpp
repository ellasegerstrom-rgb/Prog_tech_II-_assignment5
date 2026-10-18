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


int main(int argc, char *argv[])
{

    std::string input_file;
    int kgram;
    int alpha;
    int w;


    try
    {

        if (argc != 4 && argc != 6)
        {

            throw std::invalid_argument("Error: Invalid amount of arguments please enter $ slm <k-value> <training data> <output> or $ slm -a <pseudo-count> <k-value> <training data> <output>.");
        }

        if (argc == 4)
        {

            if (std::stoi(argv[1]) < 1)
            {

                throw std::invalid_argument("Error: Invalid k-value, the k-value must be a positive integer greater than 0.\n $slm <k-value> <training data> <output>");
            }

            if (std::stoi(argv[3]) < std::stoi(argv[1]))
            {

                throw std::invalid_argument("Error: Invalid output length, the output lenght must be greater than or equal to the k-value.\n $slm <k-value> <training data> <output>");
            }
        }

        if (argc == 6)
        {

            if (std::stoi(argv[3]) < 1)
            {

                throw std::invalid_argument("Error: Invalid k-value, the k-value must be a positive integer greater than 0.\n $slm -a <pseudo-count> <k-value> <training data> <output>");
            }

            if (std::stoi(argv[5]) < std::stoi(argv[3]))
            {

                throw std::invalid_argument("Error: Invalid output length, the output lenght must be greater than or equal to the k-value.\n $slm -a <pseudo-count> <k-value> <training data> <output>");
            }

            if (std::stoi(argv[2]) < 0)
            {

                throw std::invalid_argument("Error: Invalid pseudo-count, the value must be an integer greater than or equal to 0.\n $slm -a <pseudo-count> <k-value> <training data> <output>");
            }

            std::string input_file = argv[4];
        }
    }

    catch (const std::invalid_argument &e)
    {

        std::cerr << e.what() << '\n';
        return 1;
    }

    

    if (argc == 4) {

        input_file = argv[2];
        kgram = argv[1];
        alpha = 0;
        w = argv[3];
    }

    else if (argc == 6) {

        input_file = argv[4];
        kgram = argv[3];
        alpha = argv[2];
        w = argv[5];
    }

    try
    {
        TrainingData TrainingData(input_file);
        SmallLanguageModel SmallLanguageModel(kgram, alpha);
        TextGenerator TextGenerator(w, kgram);

        string training_string = TrainingData.get_training_data();
        set<char> uniqe_chars = TrainingData.get_uniqe_chars();

        map<string,double> kgram_map = SmallLanguageModel.kgram_function(training_string);

        map<string, map<char,double>> complete_map = SmallLanguageModel.complete_kgram_char_map(kgram_map, training_string, uniqe_chars);

        string generated_text = TextGenerator.generator(kgram_map, complete_map);

        TextGenerator.output_text_func(generated_text);


    }

    catch (const std::runtime_error &e)
    {

        std::cerr << e.what() << '\n';
        return 1;
    }
}
