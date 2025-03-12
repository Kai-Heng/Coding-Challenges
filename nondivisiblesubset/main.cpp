#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>


using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    // Frequency array: freq[r] = how many elements have remainder r mod k
    vector<int> freq(k, 0);
        


    // 1) Count remainders
    for (int num : s) {
        freq[num % k]++;
    }

    for(auto a : freq){
        cout << a << endl;
    }

    // 2) Build result
    // Start with at most one element from remainder 0 (if any exist).
    int result = min(freq[0], 1);

    // 3) For each pair of remainders r and k-r:
    //    we can only take from one side or the other, whichever is larger in freq.
    // We'll iterate r from 1..(k-1)/2
    for (int r = 1; r <= (k-1)/2; r++) {
        // remainder r and k-r can't both be chosen
        // pick the side with the bigger freq
        if (r != k - r) {
            result += max(freq[r], freq[k - r]);
        }
    }

    // 4) Special case if k is even: remainder k/2 can appear at most once
    if (k % 2 == 0) {
        // freq[k/2] can also appear at most once
        result += min(freq[k/2], 1);
    }

    return result;
}

int main(){
    int k = 11;
    // vector<int> s = {582740017, 954896345, 590538156, 298333230, 859747706, 155195851, 331503493, 799588305, 164222042, 563356693, 80522822, 432354938, 652248359};
    vector<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int solution = nonDivisibleSubset(4, s);

    cout << solution << endl;
}