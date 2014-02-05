/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (root == NULL)
    		return;
        TreeLinkNode *save = root;
        while(root) {
            if (!root->left && !root->right)
                break;
            root->left->next = root->right;
            if (!root->next) {
                root = save->left;
                save = root;
                continue;
            }
            root->right->next = root->next->left;
            root = root->next;
        }
    }
};