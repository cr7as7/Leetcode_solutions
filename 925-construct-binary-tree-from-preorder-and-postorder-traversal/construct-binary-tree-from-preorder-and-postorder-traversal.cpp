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
    unordered_map<int, int> postorderIndexMap;
    int preIndex = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (left == right) return root; // Single node subtree case

        int postIndex = postorderIndexMap[preorder[preIndex]]; // Get left child index

        // Recursively build left and right subtrees
        root->left = construct(preorder, postorder, left, postIndex);
        root->right = construct(preorder, postorder, postIndex + 1, right - 1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
                int n = postorder.size();
        for (int i = 0; i < n; i++) {
            postorderIndexMap[postorder[i]] = i; // Store postorder indices for lookup
        }
        return construct(preorder, postorder, 0, n - 1);
    }
};