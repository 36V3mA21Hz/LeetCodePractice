class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));    
    }
    int max(int i, int j) {
        if (i >= j) return i;
        else return j;
    }
};
