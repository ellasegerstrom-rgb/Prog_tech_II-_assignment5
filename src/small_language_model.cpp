#include "small_language_model.h"
#include <map>
#include <string>
using std::string;
using std::map;

SmallLanguageModel::SmallLanguageModel(int k_gram, int alpha) {

    this-> k_gram = k_gram;
    this-> alpha = alpha;

}

std::map<string, double> SmallLanguageModel::k_gram_function(string training_string, int k_gram) {

    std::map<string, double> k_gram_string_map;


    for (int i=0; i<= (training_string.length()-k_gram); i++) {

        string word = training_string.substr(i,k_gram);

        k_gram_string_map[word]++;
    }

return k_gram_string_map;

}



std::map<char,double> SmallLanguageModel::char_after_word(string training_string, string word, int k_gram){

    std::map<char,double> char_after_word_map;

    for (int i=0; i<= (training_string.length()-k_gram); i++){

        if (training_string.substr(i,k_gram) == word){

            char next_char = training_string[i+k_gram, i+k_gram+1];

            char_after_word_map[next_char]++;
        }
    }
    
return char_after_word_map;
}

std::map<string, double> SmallLanguageModel::prob_dist_k_gram(std::map<string, double> k_gram_string_map){

    int tot_n = 0;

    for (const auto& entry : k_gram_string_map){
        tot_n += entry.second;
    }

    if(tot_n ==0) {
        return k_gram_string_map;
    }

    for (auto& entry : k_gram_string_map){

        entry.second = entry.second/tot_n;
    }

return k_gram_string_map;

};


std::map<char, double> SmallLanguageModel::prob_dist_next_char(std::map<char, double>, int alpha) {




}
















