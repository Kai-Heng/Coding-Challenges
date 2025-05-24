#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> arr;

    for(int i = 0; i < words.size(); i++){
        int left = 0;
        int right = words[i].size()-1;
        while(left <= right){
            if(words[i][left] == x){
                arr.push_back(i);
                break;
            }

            if(words[i][right] == x){
                arr.push_back(i);
                break;
            }

            left++;
            right--;
        }
    }

    return arr;
}