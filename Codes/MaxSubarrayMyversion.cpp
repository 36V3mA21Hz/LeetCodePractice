class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n == 0)
			return 0;
		int max = 0, buffer_J_minus1_k_minus1 = 0;
		for (int i = 0; i < n; i++) {
			if (buffer_J_minus1_k_minus1 > 0) {
				max += buffer_J_minus1_k_minus1 + A[i];
				buffer_J_minus1_k_minus1 = 0;
			} else if (A[i] > max) {
				max = A[i];
				buffer_J_minus1_k_minus1 = 0;
			} else {
				buffer_J_minus1_k_minus1 += A[i];
			}
		}
		return max;
	}
};