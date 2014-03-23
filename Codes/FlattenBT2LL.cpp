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
    void flatten(TreeNode *root) {
        if (!root)
        	return;
        stack<TreeNode*> store;
        preOrderFlatten(root, store);
        TreeNode *child = NULL, *parent = NULL;
        while (!store.empty()) {
        	parent = store.top();
        	store.pop();
        	parent->right = child;
        	parent->left = NULL;
        	child = parent;
        }
    }
    void preOrderFlatten(TreeNode *node, stack<TreeNode*> &store) {
    	if (!node)
    		return;
    	store.push(node);
    	preOrderFlatten(node->left, store);
    	preOrderFlatten(node->right, store);
    }
};
