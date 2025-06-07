#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

string robotWithString(string s) {
    int n = s.size();
    vector<char> suffMin(n);
    suffMin[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; --i)
        suffMin[i] = min(s[i], suffMin[i + 1]);

    string ans;
    string stack;               // use string as char‑stack

    for (int i = 0; i < n; ++i) {
        stack.push_back(s[i]);

        while (!stack.empty() &&
                (i == n - 1 || stack.back() <= suffMin[i + 1]))
        {
            ans.push_back(stack.back());
            stack.pop_back();
        }
    }
    return ans;
}