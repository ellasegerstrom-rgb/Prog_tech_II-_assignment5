#ifndef small_language_model_h
#define small_language_model_h

#include <map>
#include <string>
#include <iostream>

using std::string;
using std::map;


class SmallLanguageModel {

    private: 
        int k_gram;  // the gram or like the lenght of the "word" that we want to chech what comes next. 
        int alpha;  //the pseudo-count


    public:
        SmallLanguageModel( int k_gram, int alpha);

        std::map<int, std::string> Training_function(std::string training_string);

        std::map<string, double> k_gram_function(string training_string, int k_gram);
        
        std::map<char, double> char_after_word(string trining_string, string word, int k_gram);

        std::map<string, double> prob_dist_k_gram(std::map<string, double> k_gram_string_map);
    
        std::map<char, double> prob_dist_next_char(std::map<char, double>, int alpha);
    
    };


#endif