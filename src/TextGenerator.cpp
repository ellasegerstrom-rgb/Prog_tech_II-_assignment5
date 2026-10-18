#include "TextGenerator.h"

TextGenerator::TextGenerator(int w, int kgram){

    if(w<kgram){

        throw std::invalid_argument("Error: <output> must be equal or larger than <k_gram> to be able to generate text.");

    }

    this-> w = w;
}


char TextGenerator::generate_next_char(const map<char, double>& char_prob_map){

    vector<char> chars;
    vector<double> char_dist;

    for (const auto& entry : char_prob_map) {

        if (entry.second > 0) {

            chars.push_back(entry.first);

            char_dist.push_back(entry.second);
        }
    }

    if (chars.empty()) {
        throw std::runtime_error("No possible next character.");
    }

    static std::mt19937 gen(std::random_device{}());

    std::discrete_distribution<> dist(char_dist.begin(), char_dist.end());

    return chars[dist(gen)];

}



string TextGenerator::generator(const map<string,double>& kgram_map, const map<string,map<char,double>>& char_dist_map){

    vector<string> kgrams;
    vector<double> kgram_dist;

    for (const auto& entry : kgram_map) {

        if (entry.second > 0) {

            kgrams.push_back(entry.first);

            kgram_dist.push_back(entry.second);
        }
    }

    if (kgrams.empty()) {
        throw std::runtime_error("No k-grams available.");
    }

    static std::mt19937 gen(std::random_device{}());

    std::discrete_distribution<> dist(kgram_dist.begin(), kgram_dist.end());

    string current_kgram = kgrams[dist(gen)];
    string new_text=current_kgram;


    while(new_text.size()<w){

        map<char, double> current_dist = char_dist_map.at(current_kgram);
        char next_char = generate_next_char(current_dist);
        new_text+=next_char;
        current_kgram = current_kgram.substr(1)+next_char;
    }

    return new_text;

}




void TextGenerator::output_text_func(const string& generated_text){

    std::cout<<generated_text<<std::endl;
}















