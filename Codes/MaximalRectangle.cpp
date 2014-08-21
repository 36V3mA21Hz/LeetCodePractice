class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;
		int m = matrix.size(), n = matrix[0].size();
		int maxArea = 0;
		vector<int> lengths(n + 1, 0);
		vector<int> widths(n + 1, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					if (widths[j] && widths[j + 1]) {
						widths[j + 1] = min(widths[j + 1] + 1, widths[j]);
						lengths[j + 1] = min(lengths[j + 1], lengths[j] + 1);
					}
					else if (widths[j]) {
						widths[j + 1] = widths[j];
						lengths[j + 1] = lengths[j] + 1;
					}
					else if (widths[j + 1]) {
						widths[j + 1] = widths[j + 1] + 1;
						lengths[j + 1] = lengths[j + 1];
					}
					else {
						widths[j + 1] = 1;
						lengths[j + 1] = 1;
					}
					maxArea = max(maxArea, widths[j + 1] * lengths[j + 1]);
				}
				else {
					widths[j + 1] = 0;
					lengths[j + 1] = 0;
				}
			}
		}
		return maxArea;
	}
};