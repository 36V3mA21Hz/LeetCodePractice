class Solution {
public:
    int maxPathSum(TreeNode *root) {
    	if (!root)
    		return 0;
        int maxSum = INT_MIN;
        mPSAux(root, maxSum);
        return maxSum;
    }
    int mPSAux(TreeNode *root, int &maxSum) {
    	if (!root)
        	return 0;
    	int sum = 0;
        int leftMax = mPSAux(root->left, maxSum);
        int rightMax = mPSAux(root->right, maxSum);
        if (leftMax > 0 && rightMax > 0) {
        	sum = max(leftMax, rightMax) + root->val;
        	maxSum = max(maxSum, rightMax + leftMax + root->val);
        } else if (leftMax > 0) {
        	sum = root->val + leftMax;
        	maxSum = max(maxSum, sum);
        } else if (rightMax > 0) {
        	sum = root->val + rightMax;
        	maxSum = max(maxSum, sum);
        } else {
        	sum = root->val;
        	maxSum = max(maxSum, sum);
        }
        return sum;
    }
};
