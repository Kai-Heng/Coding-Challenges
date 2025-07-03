#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <cmath>

using namespace std;

char kthCharacter(int k) {
    int ans = 0;
    int t;
    while (k != 1) {
        t = __lg(k);
        if ((1 << t) == k) {
            t--;
        }
        k = k - (1 << t);
        ans++;
    }
    return 'a' + ans;
}