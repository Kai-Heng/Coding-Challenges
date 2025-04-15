#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;

struct Grid{
    int n;
    int x;
    int y;
    int moves;
    Grid() : x(0), y(0), moves(0){}
    Grid(int n) : n(n), x(0), y(0), moves(0){}
    Grid(const Grid &other){
     n = other.n;
     x = other.x;
     y = other.y;
     moves = other.moves;
    }
  };
  
  string get_hash(int x, int y){
     return to_string(x) + "," + to_string(y);
  }
  
  vector<Grid> nextGrids(Grid g, int i, int j){
     vector<Grid> allPossibleGrid;
     if(g.x - i >= 0){
         if(g.y - j >= 0){
             Grid newG(g);
             newG.x = g.x - i;
             newG.y = g.y - j;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
         
         if(g.y + j < g.n){
             Grid newG(g);
             newG.x = g.x - i;
             newG.y = g.y + j;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
     }
     
     if(g.x + i < g.n){
         if(g.y - j >= 0){
             Grid newG(g);
             newG.x = g.x + i;
             newG.y = g.y - j;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
         
         if(g.y + j < g.n){
             Grid newG(g);
             newG.x = g.x + i;
             newG.y = g.y + j;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
     }
     
     if(g.x - j >= 0){
         if(g.y - i >= 0){
             Grid newG(g);
             newG.x = g.x - j;
             newG.y = g.y - i;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
         
         if(g.y + i < g.n){
             Grid newG(g);
             newG.x = g.x - j;
             newG.y = g.y + i;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
     }
     
     if(g.x + j < g.n){
         if(g.y - i >= 0){
             Grid newG(g);
             newG.x = g.x + j;
             newG.y = g.y - i;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
         
         if(g.y + i < g.n){
             Grid newG(g);
             newG.x = g.x + j;
             newG.y = g.y + i;
             newG.moves++;
             allPossibleGrid.push_back(newG);
         }
     }
     
     return allPossibleGrid;
  }
  
  int BFS(int i, int j, int n){
     Grid initial(n);
     deque<Grid> q;
     unordered_map<string, Grid> grid_map;
     
     q.push_back(initial);
     grid_map[get_hash(initial.x, initial.y)] = initial;
     
     while(!q.empty()){
         Grid curr = q.front();
         q.pop_front();
         
         if(curr.x == n-1 && curr.y == n-1){
             return curr.moves;
         }
         
         vector<Grid> allNextGrid = nextGrids(curr, i, j);
         for(auto next : allNextGrid){
             string nextHash = get_hash(next.x, next.y);
             
             if(grid_map.count(nextHash) == 0){
                 q.push_back(next);
                 grid_map[nextHash] = next;
             }
         }
     }
     
     
     return -1;
  }
     
 vector<vector<int>> knightlOnAChessboard(int n) {
     vector<vector<int>> dp(n-1, vector<int>(n-1));
     
     for(int i = 1; i < n; i++){
         for(int j = 1; j < n; j++){
             dp[i-1][j-1] = BFS(i, j, n);
         }
     }
     
     return dp;
 }