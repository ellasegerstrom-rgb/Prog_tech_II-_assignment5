#ifndef TextGenerator_h
#define TextGenerator_h


#include <map>
#include <string>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>
#include <random>

using std::string;
using std::map;
using std::set;
using std::vector;

class TextGenerator{

    private:
        int w;

    public:
        TextGenerator(int w, int kgram);

        char generate_next_char(const map<char, double>& char_prob_map);

        string generator(const map<string,double>& kgram_map, const map<string,map<char,double>>& char_dist_map);

        void output_text_func(const string& generated_text);


};



#endif






