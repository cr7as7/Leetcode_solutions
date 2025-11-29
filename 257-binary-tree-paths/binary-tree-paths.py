# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self,root,res,s):
        if (root is None):
            return 
        if s =='':
            s+=str(root.val)
        else:
            s=s+'->'+str(root.val)
        if root.left is None and root.right is None:
            res.append(s)
            return
        self.solve(root.left,res,s)
        self.solve(root.right,res,s)

    def binaryTreePaths(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[str]
        """
        res = []
        s = ""
        self.solve(root,res,s)
        return res
        