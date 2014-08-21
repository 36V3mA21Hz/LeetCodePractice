class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int maxArea = 0;
		for (int i = 0; i < height.size(); i++) {
			maxArea = max(maxArea, findArea(height, i, i));
		}
		return maxArea;
	}
	int findArea(vector<int> &h, int l, int r) {
		int x = h[l];
		while ((l - 1 >= 0 && h[l - 1] >= x) || (r + 1 < h.size() && h[r + 1] >= x)) {
			if (l - 1 >= 0 && h[l - 1] >= x)
				l--;
			if (r + 1 < h.size() && h[r + 1] >= x)
				r++;
		}
		return (r - l + 1) * x;
	}
};