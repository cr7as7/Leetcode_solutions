/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorderMarkParent(TreeNode* root,
                           unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        if (root->left)
            parent[root->left] = root;
        inorderMarkParent(root->left, parent);
        if (root->right)
            parent[root->right] = root;
        inorderMarkParent(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        inorderMarkParent(root, parent);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        q.push(target);
        int l = 0;
        while(!q.empty()){
            int n = q.size();
            if(k==0) break;
            while(n--){
                l++;
                auto t = q.front();
                q.pop();
                if(t->left != NULL && !vis.count(t->left)){
                    q.push(t->left);
                    vis.insert(t->left);
                }
                if(t->right != NULL && !vis.count(t->right)){
                    q.push(t->right);
                    vis.insert(t->right);
                }
                if(parent[t] != NULL && !vis.count(parent[t])){
                    q.push(parent[t]);
                    vis.insert(parent[t]);
                }
                
            }
            k--;
        }
        vector<int> res;
        while(!q.empty()){
            auto t= q.front();
            q.pop();
            if(t) res.push_back(t->val);
        }

        return res;
    }
};