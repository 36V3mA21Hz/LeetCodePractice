# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param p, a tree node
    # @param q, a tree node
    # @return a boolean
    def isSameTree(self, p, q):
        if p == None and q != None or p != None and q == None:
            return False
        if p == None and q == None:
            return True
        if p.val != q.val:
            return False
        q1 = self.isSameTree(p.left, q.left)
        q2 = self.isSameTree(p.right, p.right)
        return True and q1 and q2