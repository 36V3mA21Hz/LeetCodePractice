class Solution {
public:
	int maxSubArray(int A[], int n) {
		int maxLeft = 0;
		int maxRight = 0;
		int maxSofar = A[0];
		int maxRight2Cur = 0;
		for (int cur = 1; cur < n; cur++) {
			if (maxRight2Cur + A[cur] > 0) {
				if (maxSofar > A[cur] || maxSofar + maxRight2Cur > 0) {
					maxSofar += A[cur] + maxRight2Cur;
					maxRight = cur;
					maxRight2Cur = 0;
				} else {
					maxSofar = A[cur];
					maxLeft = cur;
					maxRight = cur;
					maxRight2Cur = 0;
				}
			} else {
				if (maxSofar <= A[cur]) {
					maxSofar = A[cur];
					maxLeft = cur;
					maxRight = cur;
					maxRight2Cur = 0;
				} else {
					maxRight2Cur += A[cur];
				}
			}
		}
		return maxSofar;
	}
};