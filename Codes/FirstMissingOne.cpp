class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0)
        	return 1;
        int minv = INT_MAX, maxv = 0;
        for (int i = 0; i < n; i++) {
        	if (A[i] > 0) {
           		if (A[i] < minv - 1)
           			minv = maxv = A[i];
           		else if (A[i] == minv - 1)
           			minv--;
           		else if (A[i] == maxv + 1)
           			maxv++; 
        	}
        }
        if (minv == 1)
        	return maxv + 1;
        return 1;
    }
};