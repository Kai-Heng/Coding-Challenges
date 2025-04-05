#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

vector<int> cutTheSticks(vector<int> arr) {
    vector<int> sticks_cut;
    sort(arr.begin(), arr.end());
    deque<int> q(arr.begin(), arr.end());
    
    while(!q.empty()){
        int min_el = q.front();
        sticks_cut.push_back(q.size());
        
        while(!q.empty() && q.front() == min_el){
            q.pop_front();
        }
    }
    
    return sticks_cut;
}