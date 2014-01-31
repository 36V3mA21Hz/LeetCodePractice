class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if (matrix.empty())
    		return false;
    	int m = matrix.size();
    	int n = matrix.front().size();
    	int rowIndex ;
    	bool rowIndexfound = false;
    	for (int i = m - 1; i >= 0; i--) {
    		if (target >= matrix[i][0]) {
    			rowIndex = i;
    			rowIndexfound = true;
    			break;
    		}
    	}
    	if (!rowIndexfound)
    		return false;
    	for (int j = 0; j < n; j++) {
    		if (target == matrix[rowIndex][j])
    			return true;
    	}      
    	return false;
    }
};