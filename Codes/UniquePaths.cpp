class Solution {
public:
	unsigned long uniquePaths(int m, int n) {
	    if (m == 1 || n == 1) return 1;
	    int x = m - 1;
	    int y = n - 1;
	    int q;
	    if (x < y)
	    	q = x;
	    else
	    	q = y;
	    unsigned long r1 = factorial(x + y, q);
	    unsigned long r2 = factorial(q, q);
	    return r1 / r2;
	}
	unsigned long factorial(int x, int n) {
	    unsigned long result = 1;
	    for (int i = 1; i <= n; i++) {
	        result *= x - i + 1;
	    }
	    return result;
	}
};