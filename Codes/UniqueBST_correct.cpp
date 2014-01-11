class Solution {
public:
	int numTrees(int n) {
		if (n <= 1) return 1;
		if (n == 2) return 2;
		int i = 1, y = 0;
		while (i <= n) {
			y += numTrees(i - 1) * numTrees(n - i);
			i++;
		}
		return y;
	}
};