#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        bool dfs(vector<vector<char>> &board, string word, int word_i, int i, int j){
            if(word_i == word.length()) return true;
            if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == '#' || board[i][j] != word[word_i]) return false;
            
            char temp = board[i][j];
            board[i][j] = '#'; // mark visited
            bool found = dfs(board, word, word_i+1, i, j+1) ||
                    dfs(board, word, word_i+1, i, j-1) ||
                    dfs(board, word, word_i+1, i+1, j) ||
                    dfs(board, word, word_i+1, i-1, j);
            
            board[i][j] = temp;
            return found;
        }
        bool exist(vector<vector<char>>& board, string word) {
            unordered_map<char, int> board_count, word_count;
            for (auto& row : board)
                for (char c : row)
                    board_count[c]++;
            for (char c : word)
                word_count[c]++;
            for (auto& [c, count] : word_count)
                if (board_count[c] < count)
                    return false; // Not enough characters, prune early
            
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j] == word[0]){
                        if(dfs(board, word, 0, i, j)) return true;
                    }
                }
            }
            return false;
        }
        
        
    };