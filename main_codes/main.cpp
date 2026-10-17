#include "slm.h"
#include <iostream>
#include<fstream>
#include <string>

using namespace std;

int main(int argc , char *argv[]) {
    //two parameters argv[], argv[1] is datafile, argv[2] is k-value
    try {
        double alpha = 0.0; 
        int k = 0; 
        string filename = "";
        int word_length = 0; 

        if (argc == 6 && string(argv[1]) == "-a") {
            alpha = stod(argv[2]); 
            k = stoi(argv[3]); 
            filename = argv[4]; 
            word_length = stoi(argv[5]); 
        }
        else if (argc == 4){
            alpha = 0.0; 
            k = stoi(argv[1]); 
            filename = argv[2]; 
            word_length= stoi(argv[3]); 
        }

        Slm model(k, alpha); 
        model.train(filename); 
        model.generate(word_length); 
    }

    catch (const exception& e) {
        cerr<< "Error: " <<e.what() <<endl;
        return 1; 
    }
    return 0; 
}