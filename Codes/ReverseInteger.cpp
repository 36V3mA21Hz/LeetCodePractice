class Solution {
public:
	int reverse(int x) {
		int i;
		long y = 0;
		if (x < 0) {
			x = -x;
			while (x != 0) {
				i = x % 10;
				y = 10 * y + i;
				x = (x - i) / 10;
			}
			y = -y;
		}
		else {
			while (x != 0) {
				i = x % 10;
				y = 10 * y + i;
				x = (x - i) / 10;
			}
		}
		if (y > INT_MAX) {
			y = INT_MAX;
		}
		return (int)y;
	}
};