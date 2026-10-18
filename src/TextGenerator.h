#ifndef TextGenerator_h
#define TextGenerator_h


#include <map>
#include <string>
#include <iostream>
#include <set>
#include <stdexcept>

using std::string;
using std::map;
using std::set;

class TextGenerator{

    private:
        int w;

    public:
        TextGenerator(int w, int kgram);

        string generator();








};



#endif






