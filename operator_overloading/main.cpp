#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Matrix{
    vector<vector<int>> a;
    Matrix operator+(Matrix &other){
      Matrix temp;
      temp.a.resize(a.size(), vector<int>(a[0].size(), 0));
      for(int i = 0; i < a.size(); i++){
          for(int j = 0; j < a[i].size(); j++){
              temp.a[i][j] += a[i][j] + other.a[i][j];
          }
      }
      
      return temp;
    }
  };