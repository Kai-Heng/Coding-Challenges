#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;    
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
};

void flatten(TreeNode* root) {
    if(root == nullptr) return;
    
    flatten(root->left);
    flatten(root->right);
    
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    
    root->left = nullptr;
    root->right = l;
    
    TreeNode* curr = root;
    
    while(curr->right){
        curr = curr->right;
    }
    curr->right = r;
}