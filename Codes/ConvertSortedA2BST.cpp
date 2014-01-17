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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.empty()) return NULL;
		int r = num.size() - 1;
		TreeNode *root = recFill(0, r, num);
		return root;
	}
	TreeNode *recFill(int l, int r, vector<int> &num) {
		if (l > r) return NULL;
		int mid = (l + r) / 2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = recFill(l, mid - 1, num);
		root->right = recFill(mid + 1, r, num);
		return root;
	}
};