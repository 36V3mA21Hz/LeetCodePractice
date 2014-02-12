class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        vector<int> buffer(n, 0);
        if (!obstacleGrid[0][0])
            buffer[0] = 1;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0])
                buffer[0] = 0;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j])
                    buffer[j] = 0;
                else
                    buffer[j] = buffer[j-1] + buffer[j];
            }
        }
        return buffer[n-1];
    }
};