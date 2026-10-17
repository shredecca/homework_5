// class declaration header

#ifndef SLM_H
#define SLM_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

    struct Transition {
        char character; 
        int count;  
    };     
    struct k_gram {
        std::string kgram; 
        std::vector<Transition> transitions; 
        int total_count = 0; 
    }; 

class Slm {
    private: 
        int k;   
        double alpha; 
        std::vector<k_gram> record; 
        std::set<char> alphabet; 

    public: 
    Slm(int k_value, double alpha_value = 0.0); 
    void train(const std::string& filename); 
    void generate(int word_length); 

}; 

#endif 