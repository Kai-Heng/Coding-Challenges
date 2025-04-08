#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> stones(int n, int a, int b) {
/**
 * 
    vector<int> result;
    for(int i = min(a, b) * (n-1); i < max(a,b) * (n-1); i += abs(b - a)) result.push_back(i);
    result.push_back(max(a, b) * (n-1));
    return result;
*/
    // DP solution
    vector<vector<int>>dp(n, vector<int>(n, 0));
    vector<int> ans;
    
    for(int i = 0; i < dp.size(); i++){
        int count_a = n - i-1;
        for(int j = 1; j < n; j++){
            if(count_a){
                dp[i][j] = dp[i][j-1] + a;
                count_a--;
            }
            else{
                dp[i][j] = dp[i][j-1] + b;
            }
        }
    }
    for(int i = 0; i < dp.size(); i++){
        if(ans.empty() || ans[ans.size()-1] != dp[i][n-1])
            ans.push_back(dp[i][n-1]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
