class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int tempSum, sum, index;
    	tempSum = sum = A[0];
    	for (int i = 1; i < n; i++) {
    		if (tempSum + A[i] > sum) {
    			sum = tempSum + A[i];
    			index = i;
    		}
    		tempSum += A[i];
    
    	}
    	tempSum = A[index];
    	for (int i = index - 1; i >= 0; i--) {
    		if (tempSum + A[i] > sum) sum = tempSum + A[i];
    		tempSum += A[i];
    	}
    	return sum;
    }
};