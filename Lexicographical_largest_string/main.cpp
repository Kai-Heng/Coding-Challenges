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

string answerString(string word, int numFriends) {
    int n = word.size();
    string best;

    if(numFriends == 1){
        return word;
    }

    for (int i = 0; i < n; ++i) {
        // largest j that still satisfies condition (∗)
        long long j = 1LL * n - (numFriends - i);
        if (j >= n) j = n - 1;
        if (j < i) continue;                 // no feasible segment

        string cand = word.substr(i, j - i + 1);
        if (cand > best) best.swap(cand);
    }
    return best;
}