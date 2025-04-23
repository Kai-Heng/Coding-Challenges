#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> trees;
unordered_set<int> to_delete_set;
TreeNode* helper(TreeNode* root){
    if (!root) return nullptr;

    root->left = helper(root->left);
    root->right = helper(root->right);
    
    if (to_delete_set.count(root->val)) {
        if (root->left) trees.push_back(root->left);
        if (root->right) trees.push_back(root->right);
        return nullptr;  // delete current node
    }
    return root;
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    to_delete_set = unordered_set<int>(to_delete.begin(), to_delete.end());
    if (!to_delete_set.count(root->val)) {
        trees.push_back(root);  // root is not deleted, part of forest
    }
    helper(root);
    return trees;
}