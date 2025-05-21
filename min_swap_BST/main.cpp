#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int,vector<int>> level;
void helper(TreeNode* root, int d){
    if(!root) return;

    level[d].push_back(root->val);
    helper(root->left, d+1);
    helper(root->right, d+1);
}
int minimumOperations(TreeNode* root) {
    int min_ops = 0;
    helper(root, 1);

    for(auto l : level){
        for(int i = 0; i < l.second.size(); i++){
            int min_el = l.second[i];
            int idx = i;
            for(int j = i + 1; j < l.second.size(); j++){
                if(min_el > l.second[j]){
                    min_el = l.second[j];
                    idx = j;
                }
            }
            if(idx != i){
                swap(l.second[idx], l.second[i]);
                min_ops++;
            }
        }
    }

    return min_ops;
}