#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> freq;
    int n = s.size();

    // 1. Generate all substrings
    for(int start = 0; start < n; ++start){
        for(int length = 1; length <= n - start; ++length){
            // 2. Get the substring
            string sub = s.substr(start, length);
            // Sort to get its signature
            sort(sub.begin(), sub.end());
            // 3. Count the signature
            freq[sub]++;
        }
    }

    // 4. Sum up the pairs for each signature
    int result = 0;
    for (auto &p : freq) {
        cout << p.first << " " << p.second << endl;
        int count = p.second;
        // Number of ways to pick 2 from 'count' is count*(count-1)/2
        if (count > 1) {
            result += (count * (count - 1)) / 2;
        }
    }

    return result;
}

int main(){
    string s = "ifailuhkqq";

    cout << sherlockAndAnagrams(s) << endl;
}