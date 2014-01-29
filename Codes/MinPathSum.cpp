class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	if (grid.empty()) return 0;
    	int min = INT_MAX;
    	minPathSumAux(grid, min, 0, 0, 0);
    	return min;
    }
    void minPathSumAux(vector<vector<int>> &grid, int &min, int temp, int row, int column) {
    	if (column == grid.size()) 
    		return;
    	if (row == grid.size()) 
    		return;
    	temp += grid[row][column]; 
    	minPathSumAux(grid, min, temp, row, column + 1);
    	minPathSumAux(grid, min, temp, row + 1, column);
    	min = temp < min ? temp : min;
    }
};