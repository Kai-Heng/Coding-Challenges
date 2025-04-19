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

pair<int, TreeNode*> dfs(TreeNode* node) {
    if (!node) return {0, nullptr};

    auto left = dfs(node->left);
    auto right = dfs(node->right);

    if (left.first == right.first) {
        return {left.first + 1, node}; // current node is LCA
    } else if (left.first > right.first) {
        return {left.first + 1, left.second};
    } else {
        return {right.first + 1, right.second};
    }
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return dfs(root).second;
}