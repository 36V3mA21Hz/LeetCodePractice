class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		if (n == 0) return;
		int *pa = A, *pb = B;
		int *paL = pa + m, *pbL = pb + n;
		int *temp = new int[m + n];
		for (int i = 0; i < n + m; i++) {
			if (pa == paL) {
				temp[i] = *(pb++);
			}
			else if (pb == pbL) {
				temp[i] = *(pa++);
			}
			else if (*pa < *pb) {
				temp[i] = *(pa++);
			}
			else if (*pa >= *pb) {
				temp[i] = *(pb++);
			}
		}
		for (int i = 0; i < n + m; i++) {
			A[i] = temp[i];
		}
	}
};