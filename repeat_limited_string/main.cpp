#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
    string res = "";
    sort(s.begin(), s.end());

    deque<char> q;

    char prev_c = '/0';
    int cnt = 0;
    while(!s.empty()){
        if(s.back() != prev_c){
            res += s.back();
            cnt = 1;
            prev_c = s.back();
            s.pop_back();
        }
        else if(s.back() == prev_c && cnt < repeatLimit){
            res += s.back();
            cnt++;
            s.pop_back();
        }
        else{
            q.push_front(s.back());
            s.pop_back();
        }
        while(!q.empty()){
            if(q.back() == prev_c && cnt >= repeatLimit){
                break;
            }

            res += q.back();
            if(q.back() == prev_c && cnt < repeatLimit){
                cnt++;
            }
            else if(q.back() != prev_c){
                prev_c = q.back();
                cnt = 1;
            }
            q.pop_back();
        }
    }
    return res;
}