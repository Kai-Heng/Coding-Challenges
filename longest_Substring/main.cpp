#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <queue>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> found;
    vector<char> substring;
    int longest = 0;
    int track = 0;

    for(int i = 0; i < s.length(); i++){
        if(found.count(s[i]) == 0){
            found.insert(s[i]);
            substring.push_back(s[i]);
            track++;
        }
        else{
            longest = max(longest, track);
            auto it = find(substring.begin(), substring.end(), s[i]);
            
            int remove_count = it - substring.begin() + 1;

            // Remove characters up to and including the duplicate
            for (int j = 0; j < remove_count; j++) {
                found.erase(substring[j]);
            }
            substring.erase(substring.begin(), it + 1);

            substring.push_back(s[i]);
            found.insert(s[i]);

            track = substring.size();

        }
    }

    return max(longest, track);
}