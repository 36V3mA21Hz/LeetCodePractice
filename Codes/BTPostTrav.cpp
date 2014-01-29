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
    vector<int> postorderTraversal(TreeNode *root) {
    	if (root == NULL)
    		return {};
    	vector<int> output;
    	postTravAux(root, output);
    	return output;
    }
    void postTravAux(TreeNode *node, vector<int> &buffer) {
    	if (node == NULL)
    		return;
    	postTravAux(node->left, buffer);
    	postTravAux(node->right, buffer);
    	buffer.push_back(node->val);
    }
};