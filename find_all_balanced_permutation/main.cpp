#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;
    long long modPow(long long a,long long e){
        long long r = 1;
        while (e){
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }
public:
    int countBalancedPermutations(string num) {
        const int n = num.size();
        vector<int> cnt(10,0);
        for (char c: num) cnt[c-'0']++;

        int tot = 0;
        for (int d = 0; d < 10; ++d) tot += cnt[d]*d;
        if (tot & 1) return 0;                 // odd total → impossible
        const int target = tot/2;

        const int evenPos = (n+1)/2;           // indices 0,2,4,...
        const int oddPos  = n/2;

        /* factorials up to 80 */
        vector<long long> fact(n+1), invF(n+1);
        fact[0]=invF[0]=1;
        for (int i=1;i<=n;++i) fact[i]=fact[i-1]*i%MOD;
        invF[n]=modPow(fact[n],MOD-2);
        for (int i=n;i>=1;--i) invF[i-1]=invF[i]*i%MOD;

        /* dp[e][s] = Σ prod invFact for chosen digits so far */
        vector<vector<long long>> dp(evenPos+1,
                                     vector<long long>(target+1,0));
        dp[0][0]=1;

        for (int val=0; val<=9; ++val){
            int c = cnt[val];
            if (!c) continue;

            vector<vector<long long>> nxt(evenPos+1,
                                          vector<long long>(target+1,0));

            for (int e=0; e<=evenPos; ++e)
                for (int s=0; s<=target; ++s) if (dp[e][s]){
                    for (int take=0; take<=c && e+take<=evenPos
                                    && s+take*val<=target; ++take){
                        long long add = dp[e][s]
                                        * invF[take]   % MOD
                                        * invF[c-take] % MOD;
                        int ne = e + take;
                        int ns = s + take*val;
                        nxt[ne][ns] = (nxt[ne][ns] + add) % MOD;
                    }
                }
            dp.swap(nxt);
        }

        long long ways = dp[evenPos][target];
        ways = ways * fact[evenPos] % MOD * fact[oddPos] % MOD;
        return (int)ways;
    }   
};