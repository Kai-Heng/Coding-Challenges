#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

string balancedSums(vector<int> arr) { 
    // O(n^2)
    // for(int i = 0; i < arr.size(); i++){
    //     long long sub1 = 0;
    //     long long sub2 = 0;
    //     cout << arr[i] << endl;
    //     for(int j = 0; j < arr.size(); j++){
    //         if(i != j){
    //             if(j < i)
    //                 sub1 += arr[j];
    //             else{
    //                 sub2 += arr[j];
    //             }
    //         }
    //     }
        
    //     cout << sub1 << " " << sub2 << endl;
    //     if(sub1 == sub2){
    //         return "YES";
    //     }
    // }
    
    // O(n)
    vector<int> dp(arr.size()+1);
    dp[0];
    
    for(int i = 1; i < dp.size(); i++){
        dp[i] += dp[i-1] + arr[i-1];
    }
    
    int total = dp[dp.size()-1];
    
    for(int i = 0; i < arr.size(); i++){
        if(dp[i+1] - arr[i] == total - dp[i+1]){
            return "YES";
        }
    }
    return "NO";
}