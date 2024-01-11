# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def differ(self, root, minVal, maxVal):
        if not root:
            return maxVal - minVal
        
        minVal = min(root.val, minVal)
        maxVal = max(root.val, maxVal)
        
        leftDiff = self.differ(root.left, minVal, maxVal)
        rightDiff = self.differ(root.right, minVal, maxVal)
        
        return max(leftDiff, rightDiff)
    
    def maxAncestorDiff(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        return self.differ(root, root.val, root.val)