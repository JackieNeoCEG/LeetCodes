# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        leaves1 = self.getLeafSequence(root1)
        leaves2 = self.getLeafSequence(root2)

        return leaves1 == leaves2

    def getLeafSequence(self, root):
        if not root:
            return []

        if not root.left and not root.right:
            return [root.val]

        left_leaves = self.getLeafSequence(root.left)
        right_leaves = self.getLeafSequence(root.right)

        return left_leaves + right_leaves
        