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

// O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) {
        return root; // p and q found in different subtrees
    }
    
    return left ? left : right; // Either one child returns non-null (meaning found)
}

// O(n^2)
/**
unordered_map<TreeNode*, unordered_set<int>> table;
unordered_set<int> helper(TreeNode* root){
    if (!root) return {};

    unordered_set<int> mySet;

    // Get left and right subtree descendants
    unordered_set<int> leftSet = helper(root->left);
    unordered_set<int> rightSet = helper(root->right);

    // Add all descendants from left and right into current set
    mySet.insert(leftSet.begin(), leftSet.end());
    mySet.insert(rightSet.begin(), rightSet.end());

    // Also add immediate left and right child
    if (root->left) mySet.insert(root->left->val);
    if (root->right) mySet.insert(root->right->val);

    // Save for this root
    table[root] = mySet;

    return mySet;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    helper(root);
    int checkLowest = 1e5;
    TreeNode* common_anc = nullptr;
    for(auto t : table){
        if ((t.first->val == p->val && t.second.count(q->val)) ||
        (t.first->val == q->val && t.second.count(p->val)) ||
        (t.second.count(p->val) && t.second.count(q->val))) {
            if(t.second.size() < checkLowest){
                common_anc = t.first;
                checkLowest = t.second.size();
            }
        }
    }
    return common_anc;
}

*/