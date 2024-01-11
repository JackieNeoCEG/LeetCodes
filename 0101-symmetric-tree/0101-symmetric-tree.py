# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isMirror(self, leftSub, rightSub):
        if not leftSub and not rightSub:
            return True
        
        if not leftSub or not rightSub:
            return False
        
        return leftSub.val == rightSub.val and self.isMirror(leftSub.left, rightSub.right) and self.isMirror(leftSub.right, rightSub.left)
        
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return true
        
        return self.isMirror(root.left, root.right)
        