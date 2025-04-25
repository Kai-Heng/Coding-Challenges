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

int sum = 0;
void helper(TreeNode* root, TreeNode* parent, TreeNode* grand){
    if(!root || !parent || !grand) return;
    
    
    if(grand->val % 2 == 0) sum += root->val;

    helper(root->left, root, parent);
    helper(root->right, root, parent);
    
    return;
    
}
int sumEvenGrandparent(TreeNode* root) {
    if(root->left){
        helper(root->left->left, root->left, root);
        helper(root->left->right, root->left, root);
    }
    
    if(root->right){
        helper(root->right->left, root->right, root);
        helper(root->right->right, root->right, root);
    }
    

    return sum;
}