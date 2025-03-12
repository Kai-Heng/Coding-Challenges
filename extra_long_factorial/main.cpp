#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void multiply(string &number, int val) {
    int carry = 0;
    // We'll do it from right to left (least significant digit first).
    for (int i = number.size() - 1; i >= 0; i--) {
        // digit char to int
        int prod = (number[i] - '0') * val + carry;
        carry = prod / 10;
        number[i] = (char)('0' + (prod % 10));
    }
    // If there's leftover carry, we need to prepend it
    while (carry > 0) {
        number.insert(number.begin(), (char)('0' + (carry % 10)));
        carry /= 10;
    }
}

void extraLongFactorials(int n) {
    string result = "1";
    
    for(int i = 2; i <= n; i++){
        multiply(result, i);
    }
    
    cout << result << endl;
}