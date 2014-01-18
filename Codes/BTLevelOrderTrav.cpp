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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	if (root == NULL) return {};
    	TreeNode *n;
    	vector<TreeNode*> thisLevel;
    	vector<TreeNode*> nextLevel;
    	vector<vector<int> > wholeTree;
    	vector<int> eachLevel;

    	thisLevel.push_back(root);
    	while (!thisLevel.empty()) {
    		eachLevel.clear();
	    	while(!thisLevel.empty()) {
	    		n = thisLevel.front();
	    		thisLevel.erase(thisLevel.begin());
	    		if (n == NULL) continue;
	    		eachLevel.push_back(n->val);
	    		if (n->left) nextLevel.push_back(n->left);
	    		if (n->right) nextLevel.push_back(n->right);
	    	}
	    	thisLevel = nextLevel;
	    	nextLevel.clear();
	    	wholeTree.insert(wholeTree.begin(), eachLevel);
	    }
	    return wholeTree;  
    }

};