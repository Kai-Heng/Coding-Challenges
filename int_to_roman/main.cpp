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

using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> valueSymbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };

    string roman = "";

    for (auto &[value, symbol] : valueSymbols) {
        while (num >= value) {
            roman += symbol;
            num -= value;
        }
    }

    return roman;
}