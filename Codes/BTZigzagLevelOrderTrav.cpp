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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (!root)
        	return {};
        vector<vector<int> > output;
        vector<TreeNode*> thisLevel;
        vector<TreeNode*> nextLevel;
        bool even = true;
        thisLevel.push_back(root);

        while (!thisLevel.empty()) {
        	TreeNode *node = NULL;
        	vector<int> levelValue;
        	for (int i = 0; i < thisLevel.size(); i++) {
        		node = thisLevel[i];
        		nextLevel.push_back(node->left);
        		nextLevel.push_back(node->right);
        	}
        	if (even) {
	        	for (int i = 0; i < thisLevel.size(); i++) 
	        		levelValue.push_back(node->val);
	        } else {
	        	for (int i = thisLevel.size() - 1; i >= 0; i--) 
	        		levelValue.push_back(node->val);
	        }
	        output.push_back(levelValue);
	        thisLevel = nextLevel;
	        nextLevel.clear();
	        levelValue.clear();
	        even = !even;
        }
        return output;
    }
};