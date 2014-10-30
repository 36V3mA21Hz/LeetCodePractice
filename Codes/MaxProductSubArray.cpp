class Solution {
public:
    int maxProduct(int A[], int n) {
        if (!n) return 0;
        int globalMax = A[0], maxSofar = A[0], mulFrom0toCur = A[0], mulFromNonNegtoCur = A[0];
        int firstNeg = A[0] < 0 ? 0 : -1, zeroIndex = A[0] == 0 ? 0 : -1, negCount = 0;
        for (int i = 1; i < n; i++) {
        	mulFrom0toCur *= A[i], mulFromNonNegtoCur *= A[i];
        	if (firstNeg == -1 && A[i] < 0)
        		firstNeg = i, negCount++, mulFromNonNegtoCur = 1;
        	if (A[i] == 0) 
        		zeroIndex = i, negCount = 0, firstNeg = -1, mulFrom0toCur = 1;
    		if (negCount % 2) {
    			maxSofar = mulFromNonNegtoCur;
    		} else {
    			maxSofar = mulFrom0toCur;
    		}
        	globalMax = max(globalMax, maxSofar);
        }
        return globalMax;
    }
};