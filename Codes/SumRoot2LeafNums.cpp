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
    int sumNumbers(TreeNode *root) {
        if (!root)
        	return 0;
        int sum = 0;
        sumNumbersAux(root, 0, sum);
        return sum;
    }
    void sumNumbersAux(TreeNode *node, int temp, int &sum) {
    	if (!node) return;
    	temp = temp * 10 + node->val;
    	if (node->left == NULL && node->right == NULL) {
    		sum += temp;
    		return;
    	}
    	sumNumbersAux(node->left, temp, sum);
    	sumNumbersAux(node->right, temp, sum);
    }
};