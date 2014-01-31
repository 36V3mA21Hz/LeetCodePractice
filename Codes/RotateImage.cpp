class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int len, j = 0;
        for (len = n - 1; len > 0; len -= 2, j++) {
        	for (int i = j; i < len + j; i++) {
    			int temp = matrix[j][i];
    			matrix[j][i] = matrix[n-1-i][j];
    			matrix[n-1-i][j] = matrix[n-1-j][n-1-i];
    			matrix[n-1-j][n-1-i] = matrix[i][n-1-j];
    			matrix[i][n-1-j] = temp;
        	}
        }
    }
};
