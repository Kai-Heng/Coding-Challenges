#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

int find_triplets_production(int n){
    int max_product = -1;

    for (int a = 1; a <= n / 3; a++) {
        // Calculate b directly using derived formula
        int numerator = n * (n - 2 * a);
        int denominator = 2 * (n - a);
        if (denominator == 0) continue;  // Avoid division by zero
        int b = numerator / denominator;

        // Ensure b is an integer > a
        if (b > a && numerator % denominator == 0) {
            int c = n - a - b;
            if (c > b && (a * a + b * b == c * c)) {
                int product = a * b * c;
                if (product > max_product) {
                    max_product = product;
                }
            }
        }
    }

    return max_product;
}
