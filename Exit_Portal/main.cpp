#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

static const int DIR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
  // Write your code here
  // BFS, Visited
  // Find start position and record portals
  int sr=-1, sc=-1; // start row & col
  vector<vector<pair<int,int>>> portals(26); // portals['a'..'z'] -> list of cell coords

  for(int r = 0; r < R; r++){
    for(int c2 = 0; c2 < C; c2++){
      char ch = G[r][c2];
      if(ch == 'S'){
          sr = r; sc = c2;
      } else if(ch >= 'a' && ch <= 'z'){
          portals[ch - 'a'].push_back({r, c2});
      }
    }
  }

  // BFS setup
  queue<array<int,3>> q; 
  q.push({sr, sc, 0});
  vector<vector<bool>> visited(R, vector<bool>(C, false));
  visited[sr][sc] = true;

  // Track if we've used a letter's teleport expansions
  vector<bool> usedLetter(26, false);

  // BFS
  while(!q.empty()){
    auto [r, c2, dist] = q.front();
    q.pop();

    // If it's an exit, return dist
    if(G[r][c2] == 'E'){
      return dist;
    }

    // 1. Try walking (up, down, left, right)
    for(auto &d : DIR){
      int nr = r + d[0];
      int nc = c2 + d[1];
      if(nr >= 0 && nr < R && nc >= 0 && nc < C){ 
        // valid cell
        if(G[nr][nc] != '#' && !visited[nr][nc]){
            visited[nr][nc] = true;
            q.push({nr, nc, dist + 1});
        }
      }
    }

    // 2. Try teleporting if on a letter
    char ch = G[r][c2];
    if(ch >= 'a' && ch <= 'z'){
      int idx = ch - 'a';
      if(!usedLetter[idx]){
        // Teleport to all other cells with same letter
        for(auto &cell : portals[idx]){
          int rr = cell.first, cc = cell.second;
          if(!visited[rr][cc]){
              visited[rr][cc] = true;
              q.push({rr, cc, dist + 1});
          }
        }
        // Mark this letter as used so we won't expand it again
        usedLetter[idx] = true;
      }
    }
  }

  // No exit reached
  return -1;
}