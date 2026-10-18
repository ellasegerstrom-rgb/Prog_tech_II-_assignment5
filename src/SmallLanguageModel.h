#ifndef SmallLanguageModel_h
#define SmallLanguageModel_h

#include <map>
#include <string>
#include <iostream>
#include <set>

using std::string;
using std::map;
using std::set;


class SmallLanguageModel {

    private: 
        int kgram;  // the gram or like the lenght of the "word" that we want to chech what comes next. 
        int alpha;  //the pseudo-count


    public:
        SmallLanguageModel(int kgram, int alpha);

        map<int, string> Training_function(const string& training_string);

        map<string, double> kgram_function(const string& training_string);
        
        map<char, double> char_after_word(const string& trining_string, const string& word, const set<char>& unique_chars);
    
        map<string, map<char, double>> complete_kgram_char_map(const map<string, double>& kgram_map, const string& training_string, const set<char>& uniqe_chars);

        
    };


#endif