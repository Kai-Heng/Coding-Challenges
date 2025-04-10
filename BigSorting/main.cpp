#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), [](const string &a, const string &b) {
        if (a.length() == b.length())
            return a < b;
        return a.length() < b.length();
    });
    return unsorted;
}