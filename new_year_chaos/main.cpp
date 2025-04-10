#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void minimumBribes(vector<int> q) {
    // unordered_map<int, int> bride_count;
    
    // for(int i = 0; i < q.size(); i++){
    //     for(int j = i; j < q.size(); j++){
    //         if(q[i] > q[j]){
    //             bride_count[q[i]]++;
    //         }
    //     }
    // }
    
    // long sum = 0;
    // for(auto a : bride_count){
    //     if(a.second > 2){
    //         cout << "Too chaotic" << endl;
    //         return;
    //     }
    //     sum += a.second;
    // }
    
    // cout << sum << endl;
    
    long sum = 0;
    
    for(int i = 0; i < q.size(); i++){
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }

        // Only check from one position ahead of their original position (q[i] - 2)
        for (int j = max(0, q[i] - 2); j < i; ++j) {
            if (q[j] > q[i]) {
                ++sum;
            }
        }
    }
    
    cout << sum << endl;
}
