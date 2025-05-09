#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

bool solve(vector<double>& nums) {
    int n = nums.size();
    if (n == 1) {
        return fabs(nums[0] - 24) < 1e-6;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            vector<double> next;
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) next.push_back(nums[k]);
            }

            for (double val : compute(nums[i], nums[j])) {
                next.push_back(val);
                if (solve(next)) return true;
                next.pop_back();
            }
        }
    }
    return false;
}

vector<double> compute(double a, double b) {
    vector<double> res = {
        a + b,
        a - b,
        b - a,
        a * b
    };

    if (fabs(b) > 1e-6) res.push_back(a / b);
    if (fabs(a) > 1e-6) res.push_back(b / a);

    return res;
}

bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());
    return solve(nums);
}