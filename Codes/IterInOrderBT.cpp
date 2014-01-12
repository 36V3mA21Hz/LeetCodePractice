class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
    	if (root == NULL) return {};
    	TreeNode *current = root;
    	vector<int> output;
    	stack<TreeNode*> temp;
    	bool done = false;
    	while (!done) {
    		if (current != NULL) {
    			temp.push(current);
    			current = current->left;
    		} else {
    			if (temp.empty()) {
    				done = true;
    			} else {
    				current = temp.top();
    				temp.pop();
    				output.push_back(current->val);
    				current = current->right;
    			}
    		}
    	}
    	return output;
    }
};
