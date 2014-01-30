class Solution {
public:
	bool canJump(int A[], int n) {
		if (n <= 1)
			return true;
		vector<int> p(n, -1);
		canJumpAux(A, p, n, 0);
		if (p[n - 1] == 1)
			return true;
		else
			return false;
	}
	int canJumpAux(int A[], vector<int> &p, int &n, int index) {
		if (index > n - 1)
			return 0;
		if (p[index] != -1)
			return p[index];
		if (A[index] == 0 && index < n - 1)
			return 0;
		if (index == n - 1)
			return 1;
		int saveIndex = index;
		for (int i = 1; i <= A[index]; i++) {
			index += i;
			if (index >= n) break;
			p[index] = 1 * canJumpAux(A, p, n, index);
		}
		return p[saveIndex];
	}
};