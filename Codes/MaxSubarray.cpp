class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum, tempSum;
        sum = tempSum = A[0];
        for (int i = 1; i < n; i++) {
            if (tempSum < 0) {
                tempSum = A[i];
            } else {
                tempSum += A[i];
            }
            if (sum <= tempSum) sum = tempSum;
        }

        return sum;
    }
};