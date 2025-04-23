#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int addDigits(int num) {
    if (num == 0) return 0;
    return 1 + (num - 1) % 9;
}