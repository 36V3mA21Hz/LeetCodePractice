int findKthSmallest(int A[], int m, int B[], int n, int k) {
	int i = n / 2;
	int j = k - 1 - i;
	//invariant: i + j = k - 1
	int Ai_1 = i == 0 ? INT_MIN : A[i-1];
	int Bj_1 = j == 0 ? INT_MIN : B[j-1];
	int Ai = i == m ? INT_MAX : A[i];
	int Bj = j == n ? INT_MAX : B[j];

	if (Bj_1 < Ai && Ai < Bj)
		return Ai;
	if (Ai_1 < Bj && Bj < Ai)
		return Bj;

	if (Ai < Bj)
		return findKthSmallest(A+i+1, m-i-1, B, j, k-i-1);
	else
		return findKthSmallest(A, i, B+j+1, n-j-1, k-j-1);
}