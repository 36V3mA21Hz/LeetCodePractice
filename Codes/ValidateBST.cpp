/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
    	if (!root)
    		return true;
    	int prev = INT_MIN;
    	return isValidBSTAux(root, prev);
    }
    bool isValidBSTAux(TreeNode *node, int &prev) {
    	if (!node)
    		return true;
    	bool q1 = isValidBSTAux(node->left, prev);
    	if (node->val <= prev)
    		return false;
    	else
    		prev = node->val;
    	bool q2 = isValidBSTAux(node->right, prev);
    	return (q1 & q2);
    }
};