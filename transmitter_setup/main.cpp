#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(), x.end());  // Step 1: Sort house locations
int n = x.size();
int i = 0;
int transmitters = 0;

while (i < n) {
    transmitters++;  // Place a new transmitter

    // Step 2: Move to the rightmost house within range `k`
    int loc = x[i];  
    while (i < n && x[i] <= loc + k) {
        i++;
    }

    // Step 3: Place the transmitter at the rightmost possible house
    int transmitterLoc = x[i - 1]; 

    // Step 4: Move to the first house that is not covered
    while (i < n && x[i] <= transmitterLoc + k) {
        i++;
    }
}

return transmitters;
}