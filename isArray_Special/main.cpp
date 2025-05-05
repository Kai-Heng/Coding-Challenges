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

using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    const int n = nums.size();
    vector<int> pref(n, 0);                // pref[i] = #bad up to i-1

    for (int k = 0; k < n - 1; ++k) {
        int sameParity = (nums[k] & 1) == (nums[k + 1] & 1);
        pref[k + 1] = pref[k] + sameParity;
    }

    vector<bool> ans;
    ans.reserve(queries.size());

    for (auto& q : queries) {
        int l = q[0], r = q[1];
        bool ok = (pref[r] == pref[l]);    // no bad pair inside
        ans.push_back(ok);
    }
    return ans;

}