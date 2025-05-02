#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    int N = buildings.size();
    unordered_map<int, vector<int>> row, col;

    /* 1. bucket coordinates by row / column */
    row.reserve(N * 2); col.reserve(N * 2);
    for (auto& b : buildings) {
        int x = b[0], y = b[1];
        row[x].push_back(y);
        col[y].push_back(x);
    }

    /* 2. sort every bucket once */
    for (auto& [_, vec] : row) sort(vec.begin(), vec.end());
    for (auto& [_, vec] : col) sort(vec.begin(), vec.end());

    /* 3. scan all buildings */
    int covered = 0;
    for (auto& b : buildings) {
        int x = b[0], y = b[1];

        /* Row check (left / right) */
        const auto& rvec = row[x];
        int rp = lower_bound(rvec.begin(), rvec.end(), y) - rvec.begin();
        bool left  = rp > 0;
        bool right = rp < (int)rvec.size() - 1;

        /* Column check (up / down) */
        const auto& cvec = col[y];
        int cp = lower_bound(cvec.begin(), cvec.end(), x) - cvec.begin();
        bool up   = cp > 0;
        bool down = cp < (int)cvec.size() - 1;

        if (left && right && up && down) ++covered;
    }
    return covered;
}