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

// open = number of '(' already placed
// close = number of ')' already placed
void dfs(int n, int open, int close, string& cur, vector<string>& res) {
    if (cur.size() == 2 * n) {          // built one sequence
        res.push_back(cur);
        return;
    }
    if (open < n) {                     // still allowed to add '('
        cur.push_back('(');
        dfs(n, open + 1, close, cur, res);
        cur.pop_back();
    }
    if (close < open) {                 // only add ')' if it stays valid
        cur.push_back(')');
        dfs(n, open, close + 1, cur, res);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    dfs(n, 0, 0, cur, res);
    return res;
}