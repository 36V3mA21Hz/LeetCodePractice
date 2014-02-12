class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid.front().size();
        vector<int> buffer(n, INT_MAX);
        buffer[0] = 0;
        for (int i = 0; i < m; i++) {
            buffer[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                int q1 = buffer[j];
                int q2 = buffer[j-1];;
                int q = q1 < q2 ? q1 : q2;
                buffer[j] = q + grid[i][j];
            }
        }
        return buffer[n-1];
    }
};