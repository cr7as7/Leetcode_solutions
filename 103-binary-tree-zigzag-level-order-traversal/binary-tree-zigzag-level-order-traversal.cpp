/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int s, leftToRight = 0;
        vector<int> a;
        while (!q.empty()) {
            leftToRight++;
            s = q.size();
            while (s--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);

                a.push_back(t->val);
            }
            if (leftToRight % 2 == 0) {
                // for(int i=b.size()-1;i>=0;i--)
                reverse(a.begin(), a.end());
                res.push_back(a);
            } else {
                res.push_back(a);
            }
            a.clear();
        }
        return res;
    }
};