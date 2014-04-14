class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0)
        	return 0;
        int maxv = INT_MIN, minv = INT_MAX, sum = 0;
        for (int i = 0; i < n; i++) {
        	maxv = max(maxv, A[i]);
        	minv = min(minv, A[i]);
        	sum += A[i];
        }
        int brokenSum = (maxv + minv) * n / 2;
        return (sum - brokenSum);
    }
};