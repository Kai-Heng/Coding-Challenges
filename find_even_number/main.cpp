#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> res;
    unordered_set<int> seen;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] == 0 || seen.count(digits[i])) continue;
        seen.insert(digits[i]);
        for(int j = 0; j < digits.size(); j++){
            if(j == i) continue;
            for(int k = 0; k < digits.size(); k++){
                if(k != j && k != i){
                    int temp = digits[i]*100 + digits[j]*10 + digits[k];
                    if(temp % 2 == 0) res.insert(temp);
                }
            }
        }
    }
    return vector<int>(res.begin(), res.end());
}