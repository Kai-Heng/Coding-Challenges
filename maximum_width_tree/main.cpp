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

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    
    // Queue stores {node, index}
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    
    int maxWidth = 0;
    
    while (!q.empty()) {
        int size = q.size();
        unsigned long long minIndex = q.front().second;
        unsigned long long first, last;

        for (int i = 0; i < size; ++i) {
            auto [node, idx] = q.front();
            q.pop();
            idx -= minIndex;  // Normalize index to avoid overflow

            if (i == 0) first = idx;
            if (i == size - 1) last = idx;

            if (node->left) q.push({node->left, 2 * idx});
            if (node->right) q.push({node->right, 2 * idx + 1});
        }

        maxWidth = max(maxWidth, (int)(last - first + 1));
    }
    
    return maxWidth;
}