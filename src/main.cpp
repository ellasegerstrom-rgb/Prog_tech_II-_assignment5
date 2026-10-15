#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdexcept>

int main(int argc, char* argv[]) {

    try {

        if (argc!=4 && argc!=6) {

            throw std::invalid_argument("Error: Invalid amount of arguments please enter $ slm <k-value> <training data> <output> or $ slm -a <pseudo-cout> <k-value> <training data> <output>. The output must be larger or equal to the k value");
        }
    
    
        if (argc == 4) {

        }

        if (argc == 6) {

        } 
    }

    catch (const std::invalid_argument& e){

        std::cerr << e.what() << '\n';
        return 1;

    }
    
}







