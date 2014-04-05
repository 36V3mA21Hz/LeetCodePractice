class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (!root)
        	return;
        TreeNode *prev = NULL, *w1 = NULL, *w2 = NULL;
        inorderRecover(root, prev, w1, w2);
        if (w2)
            swap(w1->val, w2->val);
    }
    void inorderRecover(TreeNode *node, TreeNode *&prev, TreeNode *&w1, TreeNode *&w2) {
    	if (!node)
    		return;
    	inorderRecover(node->left, prev, w1, w2);
        if (w1) {
    		if (node->val < prev->val) {
                swap(node->val, w1->val);
                w2 = NULL;
    			return;
    		}
    	}
    	if (prev) {
    		if (node->val < prev->val) {
                w1 = prev;
                w2 = node;
    		}
            prev = node;
    	} else
            prev = node;
    	inorderRecover(node->right, prev, w1, w2);
    }
};
