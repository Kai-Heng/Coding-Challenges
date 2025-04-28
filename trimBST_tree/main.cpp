#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return nullptr;

    if (root->val < low) {
        // current root too small, trim right subtree
        return trimBST(root->right, low, high);
    }
    if (root->val > high) {
        // current root too big, trim left subtree
        return trimBST(root->left, low, high);
    }

    // root is within [low, high], recursively trim left and right
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}