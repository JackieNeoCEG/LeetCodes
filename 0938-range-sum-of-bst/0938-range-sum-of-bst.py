# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        if root is None:
            return 0
        
        value = root.val if low <= root.val <= high else 0
        
        #putting "self" ensures recursive calls within the same class
        leftVal = self.rangeSumBST(root.left, low, high)
        rightVal = self.rangeSumBST(root.right, low, high)
        
        return value + leftVal + rightVal