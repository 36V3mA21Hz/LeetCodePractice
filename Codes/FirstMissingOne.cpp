class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if (n == 0)
			return 1;
		int i = 0;
		while (i < n) {
			if (A[i] != i + 1 && A[i] >= 1 && A[i] <= n && A[A[i] - 1] != A[i])
				swap(A[i], A[A[i] - 1]);
			else
				i++;
		}
		for (int i = 0; i < n; i++) {
			if (A[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};