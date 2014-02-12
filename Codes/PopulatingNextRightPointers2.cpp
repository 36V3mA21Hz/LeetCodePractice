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
    	TreeLinkNode *nextLevel = NULL;
    	TreeLinkNode *prevNode = NULL;
    	bool nextLevelFound = false;
    	while (root) {
    		if (root->left) {
    			if (!nextLevelFound) {
    				nextLevelFound = true;
    				nextLevel = root->left;
    				prevNode = nextLevel;
    			} else {
    				prevNode->next = root->left;
    				prevNode = prevNode->next;
    			}
    		} 
    		if (root->right) {
    			if (!nextLevelFound) {
    				nextLevelFound = true;
    				nextLevel = root->right;
    				prevNode = nextLevel;
    			} else {
    				prevNode->next = root->right; 
    				prevNode = prevNode->next;
    			}
    		}
    		if (!root->next) {
    			root = nextLevel;
    			nextLevel = NULL;
    			nextLevelFound = false;
    		} else
    			root = root->next;
    	}
    }
};