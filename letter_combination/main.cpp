#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> dial = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};

    for (char digit : digits) {
        vector<string> temp;
        for (const string& comb : result) {
            for (char letter : dial[digit - '0']) {
                temp.push_back(comb + letter);
            }
        }
        result = move(temp);
    }

    return result;
}