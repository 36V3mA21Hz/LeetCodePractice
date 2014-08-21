class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int x0 = -1, y0 = -1, extra = -1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 0 && x0 == -1 && y0 == -1) {
					x0 = j, y0 = i;
				}
				else if (matrix[i][j] == 0) {
					matrix[y0][j] = 0, matrix[i][x0] = 0;
				}
			}
		}
		if (x0 == -1 || y0 == -1) return;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == y0 || j == x0) continue;
				if (matrix[y0][j] == 0 || matrix[i][x0] == 0)
					matrix[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++)
			matrix[i][x0] = 0;
		for (int j = 0; j < n; j++)
			matrix[y0][j] = 0;
	}
};