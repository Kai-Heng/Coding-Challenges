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

vector<int> result;
void DFS(int i, TreeNode* root){
    if(root == nullptr){
        return;
    }
    i++;
    if(result.size() < i)
        result.push_back(root->val);

    DFS(i, root->right);
    DFS(i, root->left);
}

vector<int> rightSideView(TreeNode* root) {
    DFS(0, root);
    
    
    return result;
}