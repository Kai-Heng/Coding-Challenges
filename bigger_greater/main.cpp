#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string biggerIsGreater(string w) {
    int n = w.size();
    
    // Step 1: Find pivot (rightmost decreasing character)
    int i = n - 2;
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }
    
    // If no pivot is found, return "no answer"
    if (i == -1) return "no answer";
    
    // Step 2: Find smallest character larger than pivot on the right
    int j = n - 1;
    while (w[j] <= w[i]) {
        j--;
    }
    
    // Step 3: Swap pivot and this character
    swap(w[i], w[j]);
    
    // Step 4: Reverse the suffix to get the smallest lexicographic order
    reverse(w.begin() + i + 1, w.end());

    return w;
}

int main(){
    vector<string> s = {"lmno",
        "dcba",
        "dcbb",
        "abdc",
        "abcd",
        "fedcbabcd",
        "zyyyvvvvvuttsrqqokjjheedccb",
        "vvvygfabrsqeitgelpxwodhdfyypoyufxnecmrtkbzbhzfbtvnffcmikqoosfzoozssonomkgmtdqfecrqtps"};
    
    for(int i = 0; i < s.size(); i++)
        cout << biggerIsGreater(s[i]) << endl;
}