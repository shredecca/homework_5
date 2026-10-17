//language model 
#include "slm.h"

using namespace std; 

Slm::Slm(int k_value, double alpha_value) {
    k = k_value; 
    alpha = alpha_value; 
}

void Slm::train(const std::string& filename){
    ifstream file(filename); 
    if(!file.is_open()) {
        throw runtime_error("Could not open training file."); 
    }

    string text = "";
    char ch; 
    while (file.get(ch)) {
        text += ch; 
    }
    file.close(); 

    if (text.length() < (size_t)k) {
        return; 
    }

    for (size_t i=0; i<= text.length() - k; i++) {
        string w = text.substr(i, k); 
        alphabet.insert(w.begin(), w.end());

        if (i+k <text.length()) {
            char c = text[i +k]; 
            alphabet.insert(c);
            
            int found_index = -1; 
            for(size_t j =0; j < record.size(); j++) {
                if (record[j].kgram ==w) {
                    found_index =j;
                    break;
                }
            }

            if(found_index == -1) {
                k_gram new_record; 
                new_record.k_gram = w; 
                record.push_back(new_record);
                found_index = record.size() -1; 
            }

            auto listss = record[found_index].transitions; 
            int char_found = -1; 
            for (size_t j =0; j < listss.size(); j++) {
                if (listss[j].character == c) {
                    char_found = j; 
                    break; 
                }
            }

            if (char_found == -1) {
                listss.push_back({c, 1}); 
            } else {
                record[char_found].total_count++; 
            }
            record[found_index].total_count++; 

        }

    }
}

void Slm::generate(int word_length) {
    cout << word_length << '\n'; 
}


