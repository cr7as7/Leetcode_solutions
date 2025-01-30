/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int res = 1;
        queue<pair<TreeNode*, long long>> q;  // Use long long to prevent overflow
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            res = max(res, (int)(end - start + 1));

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                idx -= start;  // Normalize to avoid large numbers

                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }
        }

        return res;
    }
};