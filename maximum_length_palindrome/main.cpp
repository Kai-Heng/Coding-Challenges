#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */
 
 static const int MOD = 1000000007;
 static const int MAXN = 200000; // adjust if needed
 
 // We'll store factorials and inverse factorials up to MAXN (or 2*MAXN)
 long long fact[MAXN+1], invFact[MAXN+1];
 
 // Computes x^y mod MOD via fast exponentiation
 long long modPow(long long x, long long y) {
     long long res = 1 % MOD;
     while (y > 0) {
         if (y & 1) res = (res * x) % MOD;
         x = (x * x) % MOD;
         y >>= 1;
     }
     return res;
 }
 
 // Precompute factorials and their inverses
 void buildFactorials(int n) {
     fact[0] = 1;
     for (int i = 1; i <= n; i++) {
         fact[i] = (fact[i-1] * i) % MOD;
     }
     invFact[n] = modPow(fact[n], MOD-2);  // Fermat's little theorem
     for (int i = n-1; i >= 0; i--) {
         invFact[i] = (invFact[i+1] * (i+1)) % MOD;
     }
 }
 
 // nCr helper (if needed)
 long long nCr(int n, int r) {
     if (r < 0 || r > n) return 0;
     return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
 }
 
 // We will keep global prefix counts of letters
 // prefixCount[c][i] = freq of char c in s[1..i]  (1-based indexing)
 static int prefixCount[26][MAXN+1];
 static string S;
 
 // call this once before queries
 void initialize(string s) {
     S = s;
     int n = s.size();
     
     // 1) Build prefix counts
     // We'll use 1-based indexing, so shift by 1
     for (int c = 0; c < 26; c++) {
         prefixCount[c][0] = 0;
     }
     for (int i = 1; i <= n; i++) {
         for (int c = 0; c < 26; c++) {
             prefixCount[c][i] = prefixCount[c][i-1];
         }
         prefixCount[s[i-1] - 'a'][i]++;
     }
     
     // 2) Build factorial tables up to n (or n/2). 
     // The maximum "half length" H can be up to (n/2) if you use the entire substring.
     buildFactorials(n);
 }
 
 /*
  * Complete the 'answerQuery' function below.
  *
  * The function is expected to return an INTEGER.
  * The function accepts following parameters:
  *  1. INTEGER l
  *  2. INTEGER r
  */
 
 int answerQuery(int l, int r) {
     // Return the answer for this query modulo 1000000007.
     // freq[i] = freq of letter i in S[l..r]
     int freq[26];
     for (int c = 0; c < 26; c++) {
         freq[c] = prefixCount[c][r] - prefixCount[c][l-1];
     }
     
     // count how many letters are odd
     int oddCount = 0;
     long long halfSum = 0;  // sum of floor(freq[c]/2)
     vector<int> halfFreq(26);
     for (int c = 0; c < 26; c++) {
         if (freq[c] % 2 == 1) {
             oddCount++;
         }
         halfFreq[c] = freq[c] / 2;
         halfSum += halfFreq[c];
     }
     
     // ways to permute the first half:
     // factorial(halfSum) / product( factorial(halfFreq[c]) )
     // use precomputed factorials
     long long numerator = fact[halfSum]; // factorial(halfSum)
     long long denominator = 1;
     for (int c = 0; c < 26; c++) {
         denominator = (denominator * fact[ halfFreq[c] ]) % MOD;
     }
     long long waysHalf = (numerator * modPow(denominator, MOD-2)) % MOD;
     
     // if oddCount > 0, multiply by oddCount
     long long ans = waysHalf;
     if (oddCount > 0) {
         ans = (ans * oddCount) % MOD;
     }
     
     return (int)ans;
 }