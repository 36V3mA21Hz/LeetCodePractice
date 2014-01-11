class Solution {
public:
	int numTrees(int n) {
		int i = 1, y = 0, count = 0;
		while (i <= n) {
			count = 0;
			y += rec(i, count, 1, n);
			y += count;
			i++;
		}
		return y;
	}
	int rec(int i, int &count, int l, int r) {
		if (i <= l + 1 && i >= r - 1) {
			return 1;
		}
		
		if (i <= l + 1) {
			l = i + 1;
			int j = l;
			while (j <= r)
				count += rec(j++, count, l, r);
			return 0;
		}

		if (i >= r - 1) {
			r = i - 1;
			int j = l;
			while (j <= r)
				count += rec(j++, count, l, r);
			return 0;
		}
		int j = l;
		while (j <= r) {
			count += rec(j, count, l, i - 1) * rec(j, count, i + 1, r);
			j++;
		}
		return 0;
	}
};