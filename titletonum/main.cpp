#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int sum = 0;
            int factor = 0;
            
            for(int i = columnTitle.length()-1; i >= 0; i--){
                sum += (columnTitle[i] - 'A' + 1) * pow(26, factor);
                factor++;
            }
            
            return sum;
        }
    };