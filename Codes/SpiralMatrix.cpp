class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty()) return {};
        vector<int> output;
        int m = matrix.size(), n = matrix[0].size();
        if (m < 2)
            return matrix[0];
        if (n < 2) {
            for (int i = 0; i < m; i++)
                output.push_back(matrix[i][0]);
            return output;
        }
        int i = 0, x = 0, y = 0;
        int hb = n - 1, vb = m - 1;
        while (i < m * n) {
            for (int j = 0; j < hb; j++)
                output.push_back(matrix[y][x + j]);
            for (int j = 0; j < vb; j++)
                output.push_back(matrix[y + j][x + hb]);
            for (int j = 0; j < hb; j++)
                output.push_back(matrix[y + vb][x + hb - j]);
            for (int j = 0; j < vb; j++)
                output.push_back(matrix[y + vb - j][x]);
            i += 2 * (hb + vb);
            if (hb == 0 && vb == 0) {
                output.push_back(matrix[y][x]);
                i++;
            }
            x++, y++;
            hb -= 2, vb -= 2;
        }
        return output;
    }
};