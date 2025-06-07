#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

using p = pair<char,int>;

class Compare {
public:
    bool operator()(p a, p b)
    {
        if (a.first > b.first) {
            return true;
        }
        else if(a.first == b.first && a.second < b.second){
            return true;
        }

        return false;
    }
};

string clearStars(string s) {
    priority_queue<p, vector<p>, Compare> q;
    unordered_set<int> idx;
    string newS = "";

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '*'){
            idx.insert(i);
            idx.insert(q.top().second);
            q.pop();
        }
        else{
            q.push({s[i], i});
        }
    }

    for(int i = 0; i < s.length(); i++){
        if(idx.count(i) == 0) newS.push_back(s[i]);
    }

    return newS;
}