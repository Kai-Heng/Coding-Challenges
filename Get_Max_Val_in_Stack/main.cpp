#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> getMax(vector<string> operations) {
    vector<int> stack;
    vector<int> max_el;
    vector<vector<int>> command;
    map<int,int> freq;
    
    for(auto s : operations){
        stringstream ss(s);
        string digit;
        vector<int> c;
        
        while(ss >> digit){
            c.push_back(stoi(digit));
        }
        
        command.push_back(c);
    }
    
    for(auto com : command){
        if(com.size() < 2){
            if(com[0] == 2){
                int temp = stack[stack.size()-1];
                stack.pop_back();

                freq.at(temp)--;
                if(freq.at(temp) == 0){
                    freq.erase(temp);
                }
            }
            else{
                auto it = freq.end();
                it--;
                max_el.push_back(it->first);
            }
        }
        else{
            if(freq.count(com[1]) == 0){
                freq.insert(pair<int,int>(com[1], 1));
            }
            else{
                freq.at(com[1])++;
            }
            
            stack.push_back(com[1]);
        }
    }
    
    // for(auto a : freq){
    //     cout << a.first << " " << a.second << endl;
    // }

    return max_el;
}