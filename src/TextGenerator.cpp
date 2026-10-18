#include "TextGenerator.h"

TextGenerator::TextGenerator(int w, int kgram){

    if(w<kgram){

        throw std::invalid_argument("Error: <output> must be equal or larger than <k_gram> to be able to generate text.");

    }

    this-> w = w;
}
















