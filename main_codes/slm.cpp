//language model 
#include "slm.h"
#include <random> 

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
    if (record.empty() || alphabet.empty() || word_length < k) {
        return; 
    }

    random_device random_value; 
    mt19937 gen(random_value()); 

    vector<double> kgram_weight; 
    for (size_t i = 0; i <record.size(); i++) {
        kgram_weight.push_back(record[i].total_count); 
    }
    discrete_distribution<int> kgram_dist(kgram_weight.begin(), kgram_weight.end()); 

    int start_index = kgram_dist(gen); 
    string current_w = record[start_index].kgram; 

    cout << current_w; 
    int chars_output = k; 
    vector<char> alpha_vec.size(); 

    while (chars_output < word_length) {
        int found_idx =-1; 
        for (size_t = 0; i <record.size(); i++) {
            if (record[i].kgram ==current_w) {
                found_idx = i; 
                break; 
            }
        }

        vector<double> probs(alpha_vec.size(), 0.0); 
        int n_w = 0; 
        if (found_idx != -1) {
            n_w = record[found_idx].total_count; 
        } else {
            n_w = 0; 
        }
        
        for (size_t i = 0; i < alpha_vec.size(); i++) {
            char c = alpha_vec[i]; 
            int n_wc = 0;

            if (found_idx != -1) {
                const auto& trans = record[found_idx].transitions; 
                for(size_t j= 0; j < trans.size(); j++) {
                    if(trans[j].character == c) {
                        n_wc = trans[j].count; 
                        break;
                    }
                }
            }

            probs[i] = (n_wc +alpha) / (n_w + (alpha * alphabet.size())); 
        }

        if (alpha==0.0 && n_w == 0) {
            break;
        }

        discrete_distribution<int> char_dist(probs.begin(), probs.end()); 
        char next_c = alpha_vec[char_dist(gen)]; 

        cout << next_c; 
        chars_output++;

        current_w = current_w.substr(1) + next_c; 
    }

cout << endl; 

}


