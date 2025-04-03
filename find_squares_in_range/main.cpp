#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

int squares(int a, int b) {
    
    a = ceil(sqrt(a));
    b = floor(sqrt(b));
    
    return max(0, b - a + 1);
}