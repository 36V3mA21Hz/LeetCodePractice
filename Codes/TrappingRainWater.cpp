class Solution {
public:
    int trap(int A[], int n) {
        int *rH = new int [n];
        rH[0] = A[0];
        for (int i = 1; i < n; i++) {
            rH[i] = max(rH[i - 1], A[i]);
        }
        int *lH = new int [n];
        int sum = 0;
        lH[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            lH[i] = max(lH[i + 1], A[i]);
            sum += min(lH[i], rH[i]) - A[i];
        }
        return sum;
    }
};