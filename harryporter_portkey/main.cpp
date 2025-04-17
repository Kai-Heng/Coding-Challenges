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

const string LEFT = "LEFT";
const string RIGHT = "RIGHT";
const string UP = "UP";
const string DOWN = "DOWN";

struct Grid{
    vector<string> g;
    int x,y;
    vector<string> moves;
    int wands;
    Grid(){}
    Grid(vector<string> matrix, int i, int j) : g(matrix), x(i), y(j), wands(0){}
      Grid(const Grid &other){
          g = other.g;
          x = other.x;
          y = other.y;
          moves = other.moves;
          wands = other.wands;
      }
  };
    
    string get_hash(vector<string> grid){
      string hash = "";
      for(int i = 0; i < grid.size(); i++){
          hash += grid[i];
      }
      return hash;
    }
    
    vector<Grid> nextGrids(Grid g){
       vector<Grid> allPossibleGrid;
       
       //LEFT
       if(g.y-1 >= 0 && g.g[g.x][g.y-1] != 'X'){
          Grid newG(g);
          newG.g[g.x][g.y] = '.';
          newG.g[g.x][g.y-1] = 'M';
          newG.y = g.y - 1;
          newG.moves.push_back(LEFT);
          allPossibleGrid.push_back(newG);
       }
       //RIGHT
       if(g.y+1 < g.g[0].size() && g.g[g.x][g.y+1] != 'X'){
          Grid newG(g);
          newG.g[g.x][g.y] = '.';
          newG.g[g.x][g.y+1] = 'M';
          newG.y = g.y + 1;
          newG.moves.push_back(RIGHT);
          allPossibleGrid.push_back(newG);
       }
       //UP
       if(g.x-1 >= 0 && g.g[g.x-1][g.y] != 'X'){
          Grid newG(g);
          newG.g[g.x][g.y] = '.';
          newG.g[g.x-1][g.y] = 'M';
          newG.x = g.x - 1;
          newG.moves.push_back(UP);
          allPossibleGrid.push_back(newG);
       }
       //DOWN
      if(g.x+1 < g.g.size() && g.g[g.x+1][g.y] != 'X'){
          Grid newG(g);
          newG.g[g.x][g.y] = '.';
          newG.g[g.x+1][g.y] = 'M';
          newG.x = g.x + 1;
          newG.moves.push_back(DOWN);
          allPossibleGrid.push_back(newG);
       }
       
       return allPossibleGrid;
    }
    
  
  
  vector<string> BFS(vector<string> matrix, pair<int,int> portkey, pair<int,int> starting){
      Grid initial(matrix, starting.first, starting.second);
       deque<Grid> q;
       unordered_map<string, Grid> grid_map;
       
       q.push_back(initial);
       grid_map[get_hash(initial.g)] = initial;
       
       while(!q.empty()){
           Grid curr = q.front();
           q.pop_front();
           
           if(curr.x == portkey.first && curr.y == portkey.second){
               return curr.moves;
           }
           
           vector<Grid> allNextGrid = nextGrids(curr);
           for(auto next : allNextGrid){
               string nextHash = get_hash(next.g);
               
               if(grid_map.count(nextHash) == 0){
                   q.push_back(next);
                   grid_map[nextHash] = next;
               }
           }
       }
       return {};
  }
  
  int wand_usage(vector<string> matrix, vector<string> moves, pair<int,int> starting){
      int wand_used = 0;
      int x = starting.first;
      int y = starting.second;
      string prev = "";
      for(string m : moves){
          int ways = 0;
          //LEFT
          if(y-1 >= 0 && matrix[x][y-1] != 'X' && prev != RIGHT){
              ways++;
          }
          //RIGHT
          if(y+1 < matrix[0].size() && matrix[x][y+1] != 'X' && prev!=LEFT){
              ways++;
          }
          //UP
          if(x-1 >= 0 && matrix[x-1][y] != 'X' && prev != DOWN){
              ways++;
          }
          //DOWN
          if(x+1 < matrix.size() && matrix[x+1][y] != 'X' && prev != UP){
              ways++;
          }
          
          if(ways > 1){
              wand_used++;
          }
          
          if(m == LEFT){
              y -= 1;
          }
          else if(m == RIGHT){
              y += 1;
          }
          else if(m == UP){
              x -= 1;
          }
          else if(m == DOWN){
              x += 1;
          }
          prev = m;
      }
      return wand_used;
  }
  string countLuck(vector<string> matrix, int k) {
      pair<int,int> portkey, starting;
      
      for(int i = 0; i < matrix.size(); i++){
          for(int j = 0; j < matrix[0].size(); j++){
              if(matrix[i][j] == '*'){
                  portkey.first = i;
                  portkey.second = j;
              }
              
              if(matrix[i][j] == 'M'){
                  starting.first = i;
                  starting.second = j;
              }
          }
      }
      vector<string> shortestpath = BFS(matrix, portkey, starting);
      int wand = wand_usage(matrix, shortestpath, starting);
      
      if(wand != k){
          return "Oops!";
      }
      
      return "Impressed";
  }