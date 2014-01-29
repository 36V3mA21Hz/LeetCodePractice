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
        stack<TreeNode*> store;
        TreeNode *lastnodevisited = NULL;
        TreeNode *topnode = NULL;
        while (root != NULL || !store.empty()) {
            if (root != NULL) {
                store.push(root);
                root = root->left;
            } else {
                topnode = store.top();
                if (topnode->right != NULL && lastnodevisited != topnode->right) 
                    root = topnode->right;
                else {
                    store.pop();
                    output.push_back(topnode->val);
                    lastnodevisited = topnode;
                }
            } 

        }
        return output;
    }
};