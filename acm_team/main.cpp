#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <bitset>

using namespace std;


vector<int> acmTeam(vector<string> topic) {
    vector<int> result;
    int max_count = -1;
    int number_of_max_count = 0;
    for(int i = 0; i < topic.size(); i++){
        for(int j = i + 1; j < topic.size(); j++){
            bitset<512> bits_i(topic[i]);
            bitset<512> bits_j(topic[j]);
            
            int current_1s = (bits_i | bits_j).count();
            
            if(current_1s > max_count){
                max_count = current_1s;
                number_of_max_count = 1;
            }
            else if(max_count == current_1s){
                number_of_max_count++;
            }
        }
    }
    
    
    result.push_back(max_count);
    result.push_back(number_of_max_count);
    return result;
}