class Solution {
public:
	bool canJump(int A[], int n) {
		if (n <= 1)
			return true;
		bool r[] = {false};
		canJumpAux(A, r, n-1);
	}
	bool canJumpAux(int A[], vector<int> &r, int n) {
		if (r[n])
			return r[n];
		bool q = false;
		if (A[n] >= 1) {
			q = canJumpAux(A, r, n - 1);
		} else {
			q = false;
		}
		r[n] = q;
		return q;
	}
};