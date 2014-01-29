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
    bool hasPathSum(TreeNode *root, int sum) {
    	return hasPathSumAux(root, sum, 0);
    }
    bool hasPathSumAux(TreeNode *node, int &sum, int temp) {
    	if (!node) return false;
    	temp += node->val;
    	if (node->left == NULL && node->right == NULL) {
    		if (sum == temp)
    			return true;
    		else 
    			return false;
    	}
    	
    	bool q1 = hasPathSumAux(node->left, sum, temp);
    	bool q2 = hasPathSumAux(node->right, sum, temp);
    	if (q1 || q2) 
    		return true;
    	else
    		return false;
    }
};