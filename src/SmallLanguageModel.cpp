#include "SmallLanguageModel.h"
#include <map>
#include <string>
#include <set>
using std::string;
using std::map;
using std::set;

SmallLanguageModel::SmallLanguageModel(int kgram, double alpha) {

    this-> kgram = kgram;
    this-> alpha = alpha;

}

map<string, double> SmallLanguageModel::kgram_function(const string& training_string) {

    map<string, double> kgram_string_map;

    if(training_string.length()<kgram+1){

        throw std::invalid_argument("slm: The training text was too short to contain any text after the first k-gram.");
    }

    for (int i=0; i< (training_string.length()-kgram); i++) {

        string word = training_string.substr(i,kgram);

        kgram_string_map[word]++;
    }

    int tot_freq = 0;

    for (const auto& entry : kgram_string_map) {
        tot_freq += entry.second;
    
    }

    if(tot_freq ==0) {
        return kgram_string_map;
    }

    for (auto& entry : kgram_string_map){

        entry.second = entry.second/tot_freq;
    }

return kgram_string_map;

}



map<char,double> SmallLanguageModel::char_after_word(const string& training_string, const string& word, const set<char>& uniqe_chars){

    map<char,double> char_after_word_map;

    for(char c: uniqe_chars){
        char_after_word_map[c]=0;
    }

    int tot_freq=0;
    for (int i=0; i< (training_string.length()-kgram); i++){

        if (training_string.substr(i,kgram) == word){

            char next_char = training_string[i+kgram];

            char_after_word_map[next_char]++;

            tot_freq++;
        }
    }

    double prob_denominator = tot_freq+alpha*uniqe_chars.size();

    if (prob_denominator==0){
        return char_after_word_map;
    }

    for (auto& entry : char_after_word_map){

        entry.second = (entry.second+alpha)/prob_denominator;
    }

    return char_after_word_map;

}



map<string, map<char, double>> SmallLanguageModel::complete_kgram_char_map(const map<string, double>& kgram_map, const string& training_string, const set<char>& uniqe_chars ){

    map<string, map<char, double>> complete_map;

    for(const auto& entry : kgram_map){

        string word = entry.first;

        complete_map[word]= char_after_word(training_string, word, uniqe_chars);
        
    }

    return complete_map;
    
}


















