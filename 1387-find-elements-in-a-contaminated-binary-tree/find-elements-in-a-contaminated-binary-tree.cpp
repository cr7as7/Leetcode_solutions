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
class FindElements {
public:
    TreeNode* root;
    unordered_set<int> st;
    void solve(int val, TreeNode* root) {
        if (!root) return;
        if (root) {
            root->val = val;
            if (root->left)
            {   
                st.insert(2*val+1);
                solve(2*val+1, root->left);
            }
            if (root->right)
            {
                st.insert(2*val+2);
                solve(2*val+2, root->right);
            }
            return;
        }
        return;
    }
    FindElements(TreeNode* root) {
        if (!root) return;
        this->root = root; 
        st.clear();
        st.insert(0); 
        solve(0, root);  
    }
    bool search(TreeNode* root, int target) {
        if (!root)
            return false;
        if (root->val == target)
            return true;

        return search(root->left, target) || search(root->right, target);
    }

    bool find(int target) {
        return !(st.find(target)==st.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */