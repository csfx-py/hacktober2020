def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
# Example:

# Input:

#      5
#    /   \
#   3     7
#  / \   / \
# 2   4 6   9
# Output:

#      5
#    /   \
#   7     3
#  / \   / \
# 9   6 4   2