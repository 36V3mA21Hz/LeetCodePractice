class Solution {
    int climb[1000] = {};
public:
    int climbStairs(int n) {
    	if (n == 1) return 1;
    	if (n == 2) return 2;
    	if (climb[n-1] != 0) return climb[n-1];
    	climb[n-1] = climbStairs(n - 1) + climbStairs(n - 2);
    	return climb[n-1];
    }
};