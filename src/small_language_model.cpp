#include "small_language_model.h"
#include <map>
#include <string>
using std::string;
using std::map;

SmallLanguageModel::SmallLanguageModel(int k_gram, int alpha) {

    this-> k_gram = k_gram;
    this-> alpha = alpha;

}

std::map<string, int> SmallLanguageModel::k_gram_function(string training_string, int k_gram) {

    std::map<string, int> k_gram_words;


    for (int i=0; i<= (training_string.length()-k_gram); i++) {

        string word = training_string.substr(i,k_gram);

        k_gram_words[word]++;
    }

return k_gram_words;

}



std::map<char,int> SmallLanguageModel::char_after_word(string training_string, string word, int k_gram){

    std::map<char,int> char_after_word;

    for (int i=0; i<= (training_string.length()-k_gram); i++){

        if (training_string.substr(i,k_gram) == word){

            char next_char = training_string[i+k_gram, i+k_gram+1];

            char_after_word[next_char]++;
        }
    }
    
return char_after_word;
}








