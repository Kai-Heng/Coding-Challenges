#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class solution{
    int prev = -1;
    int findSecondMinimumValue(TreeNode* root) {
        int curr = root->val;
        
        if(root == nullptr){
            return prev;
        }
        
        
        if(root->left != nullptr){
            if(root->left->val < curr){
                prev = curr;
                curr = root->left->val;
            }
            else if(root->left->val > curr && (prev == -1 || prev > root->left->val)){
                prev = root->left->val;
            }
            prev = min(prev,findSecondMinimumValue(root->left));
        }
        
        if(root->right != nullptr){
            if(root->right->val < curr){
                prev = curr;
                curr = root->right->val;
            }
            else if(root->right->val > curr && (prev == -1 || prev > root->right->val)){
                prev = root->right->val;
            }
            prev = min(prev, findSecondMinimumValue(root->right));
        }
        
        return prev;
    }
};
