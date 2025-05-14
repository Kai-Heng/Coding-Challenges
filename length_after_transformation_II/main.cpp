#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

const int MOD = 1e9 + 7;

using Matrix = vector<vector<long long>>;

// Multiply two 26×26 matrices
Matrix mul(const Matrix& A, const Matrix& B) {
    Matrix C(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i)
        for (int k = 0; k < 26; ++k)
            if (A[i][k])
                for (int j = 0; j < 26; ++j)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// Fast exponentiation
Matrix power(Matrix base, long long exp) {
    Matrix result(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i)
        result[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = mul(result, base);
        base = mul(base, base);
        exp /= 2;
    }
    return result;
}
int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    // Step 1: Build frequency vector
    vector<long long> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    // Step 2: Build transition matrix
    Matrix M(26, vector<long long>(26, 0));
    for (int i = 0; i < 26; ++i)
        for (int d = 1; d <= nums[i]; ++d)
            M[i][(i + d) % 26] = 1;

    // Step 3: Compute M^t
    Matrix Mt = power(M, t);

    // Step 4: Multiply freq * Mt
    vector<long long> finalFreq(26, 0);
    for (int j = 0; j < 26; ++j)
        for (int i = 0; i < 26; ++i)
            finalFreq[j] = (finalFreq[j] + freq[i] * Mt[i][j]) % MOD;

    long long total = 0;
    for (int i = 0; i < 26; ++i)
        total = (total + finalFreq[i]) % MOD;

    return total;
}