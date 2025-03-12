#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;
// Write any include statements here

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
