/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  bool isLeaf(Node * root){
      if(!root->left && !root->right){
          return true;
      }
      return false;
  }
  void collectLeaves(Node * node, vector<int> & res){
      if(!node) return ;
      if(isLeaf(node)) {
          res.push_back(node->data);
          return ;
      }
      collectLeaves(node->left,res);
      collectLeaves(node->right,res);
      
      return ;
  }
  void collectLeft(Node * root, vector<int> & res){
      if(!root || isLeaf(root)) return;
      
      res.push_back(root->data);
      if(root->left)
      collectLeft(root->left,res);
      else if(root->right)
      collectLeft(root->right,res);
      
      return ;
  }
  void collectRight(Node * root, vector<int> & res){
      if(!root || isLeaf(root)) return;
      
      
      if(root->right)
      collectRight(root->right,res);
      else if(root->left)
      collectRight(root->left,res);
      res.push_back(root->data);
      return ;
  }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        if(!root) return {};
    
        vector<int> res;
        res.push_back(root->data);
        collectLeft(root->left,res);
        collectLeaves(root->left,res);
        collectLeaves(root->right,res);
        collectRight(root->right,res);
        return res;
    }
};