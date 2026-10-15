#ifndef small_language_model_h
#define small_language_model_h

#include <map>


class SmallLanguageModel {

    private: 
        int k_gram;  // the gram or like the lenght of the "word" that we want to chech what comes next. 
        int alpha;  //the pseudo-count


    public:
        SmallLanguageModel( int k_gram, int alpha);
    
        

    
    
    };


#endif