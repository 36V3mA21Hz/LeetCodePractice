class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        int lm = minDepth(root->left);
        int rm = minDepth(root->right);
        if (!lm * rm)
            return max(lm, rm) + 1;
        else
            return min(lm, rm) + 1;
    }
};