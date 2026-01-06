# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxLevelSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        msum =float('-inf')
        curlevel = 1
        ans = curlevel
        q = []
        q.append(root)
        while q:
            n = len(q)
            lsum=0
            while(n>0):
                node = q.pop(0)
                lsum+=node.val
                if(node.left):
                     q.append(node.left)
                if(node.right):
                     q.append(node.right)
                n-=1
            
            if lsum>msum:
                msum=lsum
                ans = curlevel
            
            curlevel+=1
        
        return ans