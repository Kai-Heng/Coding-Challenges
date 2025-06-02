#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <numeric>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);

    // left → right
    for (int i = 1; i < n; ++i)
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;

    // right → left
    for (int i = n - 2; i >= 0; --i)
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);

    return accumulate(candies.begin(), candies.end(), 0);
}