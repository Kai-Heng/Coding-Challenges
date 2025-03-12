#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;
// Write any include statements here
/**
 * Helper function to safely count how many P (or B) are in [L, R].
 * We use a prefix array 'prefixCount' where:
 *   prefixCount[i] = number of P's (or B's) up to index (i-1) inclusively.
 * Hence the number in [L, R] = prefixCount[R+1] - prefixCount[L].
 */
long long countInRange(const vector<long long>& prefixCount, int L, int R, int N) {
    // If the range [L, R] is invalid or out of bounds, return 0
    if (L > R || R < 0 || L >= N) return 0;
    // Clamp boundaries to [0, N-1]
    L = max(L, 0);
    R = min(R, N - 1);
    return prefixCount[R + 1] - prefixCount[L];
}

// O(N) runtime
long long getArtisticPhotographCount(int N, string C, int X, int Y) {
  // Write your code here
  // 1. photograph: PAB in valid cell [X,Y]
  // 2. PAB
  // Consider artistic if:
  // - dist(P, A) is between [X,Y]
  // - dist(A, B) is between [X,Y]
  // prefixP[i] = number of 'P' from C[0..i-1]
  // prefixB[i] = number of 'B' from C[0..i-1]
  vector<long long> prefixP(N + 1, 0), prefixB(N + 1, 0);

  for (int i = 0; i < N; i++) {
      prefixP[i + 1] = prefixP[i] + (C[i] == 'P');
      prefixB[i + 1] = prefixB[i] + (C[i] == 'B');
  }

  long long result = 0;

  // Check each position for 'A'
  for (int i = 0; i < N; i++) {
      if (C[i] != 'A') continue;

      // 1) Count valid P in [i-Y, i-X], B in [i+X, i+Y] => P -> A -> B
      long long pCountLeft = countInRange(prefixP, i - Y, i - X, N);
      long long bCountRight = countInRange(prefixB, i + X, i + Y, N);

      // 2) Count valid B in [i-Y, i-X], P in [i+X, i+Y] => B -> A -> P
      long long bCountLeft = countInRange(prefixB, i - Y, i - X, N);
      long long pCountRight = countInRange(prefixP, i + X, i + Y, N);

      // Add them up
      result += pCountLeft * bCountRight;  // P-A-B
      result += bCountLeft * pCountRight;  // B-A-P
  }

  return result;
}

/**
// O(N^2) Runtime
int getArtisticPhotographCount(int N, string C, int X, int Y) {
  // Write your code here
  // 1. photograph: PAB in valid cell [X,Y]
  // 2. PAB
  // Consider artistic if:
  // - dist(P, A) is between [X,Y]
  // - dist(A, B) is between [X,Y]
  vector<int> P_indices;
  vector<int> B_indices;
  int counter = 0;
  
  for(int i = 0; i < N; i++){
    if(C[i] == 'P') P_indices.push_back(i);
    else if(C[i] == 'B') B_indices.push_back(i);
  }
  
  vector<int> PA_indices;
  vector<int> BA_indices;
  for(int i = 0; i < P_indices.size(); i++){
    for(int j = X; j <= Y; j++){
      if(P_indices[i]+j < C.length() && C[P_indices[i]+j] == 'A'){
        PA_indices.push_back(P_indices[i]+j);
      }
    }
  }
  
  for(int i = 0; i < B_indices.size(); i++){
    for(int j = X; j <= Y; j++){
      if(B_indices[i]+j < C.length() && C[B_indices[i]+j] == 'A'){
        BA_indices.push_back(B_indices[i]+j);
      }
    }
  }
  
  for(int i = 0; i < PA_indices.size(); i++){
    for(int j = X; j <= Y; j++){
      if(PA_indices[i]+j < C.length() && C[PA_indices[i]+j] == 'B'){
        counter++;
      }
    }
  }
  
  for(int i = 0; i < BA_indices.size(); i++){
    for(int j = X; j <= Y; j++){
      if(BA_indices[i]+j < C.length() && C[BA_indices[i]+j] == 'P'){
        counter++;
      }
    }
  }
  
  return counter;
}
*/
