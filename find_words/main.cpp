#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        string word = "";
    };
    
class Solution {
public:
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = word;  // Store word at the end node
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (!node->children.count(c)) return;

        node = node->children[c];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();  // Avoid duplicates
        }

        board[i][j] = '#';  // Mark visited

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto [dx, dy] : directions) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] != '#') {
                dfs(board, ni, nj, node, result);
            }
        }

        board[i][j] = c;  // Backtrack
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word : words)
            insertWord(root, word);

        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};