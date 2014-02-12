class Solution {
public:
	int uniquePaths(int m, int n) {
	    if (m == 1 || n == 1) return 1;
	    int x = m - 1;
	    int y = n - 1;
	    int q = x < y ? x : y;
        int r3 = combination(x+y, q);
	    return r3;
	}
	int combination(int x, int n) {
        int i = x;
        int num = i, denom = 1;
        while (denom <= n) {
            if (num % denom) {
                num *= --i;
            } else {
                num /= denom;
                denom++;
            }
        }
        while (i > x - n + 1)
            num *= --i;
        return num;
	}
};