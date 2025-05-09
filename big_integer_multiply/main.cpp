#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1]; // Add previous carry
            
            res[i + j + 1] = sum % 10;      // current digit
            res[i + j] += sum / 10;         // carry to higher place
        }
    }
    
    // Build result string
    string result;
    for (int num : res) {
        if (!(result.empty() && num == 0)) { // skip leading zeros
            result.push_back(num + '0');
        }
    }
    
    return result.empty() ? "0" : result;
}