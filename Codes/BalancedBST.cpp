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
    bool isBalanced(TreeNode *root) {
    	if (root == NULL) return true;

        int q1 = getHeight(root->left);
        int q2 = getHeight(root->right);
        if (q1 - q2 > 1 || q1 - q2 < -1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
    int getHeight(TreeNode *node) {
    	if (node == NULL) return 0;
        int q1 = getHeight(node->left);
        int q2 = getHeight(node->right);
        if (q1 < q2)
            return q2 + 1;
        else 
            return q1 + 1;
    }
};