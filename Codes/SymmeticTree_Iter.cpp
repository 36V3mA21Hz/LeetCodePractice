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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        vector<TreeNode*> nextVector;
        vector<TreeNode*> curVector;
        int levelControl = 1, leafcounter = 0;
        TreeNode *n;
        TreeNode *nullnode;
        curVector.push_back(root);
        while (leafcounter != levelControl) {
            leafcounter = 0;
            nextVector.clear();
            nextVector.assign(levelControl*2, NULL);
            for (int i = 0; i < levelControl; i++) {
                n = curVector[i];
                if (n == NULL) continue;
                if (n->left) nextVector[2 * i] = n->left;
                else {
                    nullnode = new TreeNode(INT_MAX);
                    nextVector[2 * i] = nullnode;
                    leafcounter++;
                }
                if (n->right) nextVector[2 * i + 1] = n->right;
                else {
                    nullnode = new TreeNode(INT_MAX);
                    nextVector[2 * i + 1] = nullnode;
                    leafcounter++;
                }
            }
            for (int i = 0; i < levelControl; i++) if (nextVector[i]->val != nextVector[levelControl * 2 - i - 1]->val) return false;
            curVector = nextVector;
            levelControl *= 2;
        }
        return true;
    }
};