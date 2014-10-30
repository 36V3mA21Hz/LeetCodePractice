class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.empty())
            return true;
        int n = s1.size();
        vector<vector<vector<int> > > mem = vector<vector<vector<int>>>(n + 1, vector<vector<int> >(n + 1, vector<int>(n + 1, 0)));
        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= 1; j--) {
                for (int k = 1; k <= n - max(i, j) + 1; k++) {
                    if (k == 1) {
                        if (s1[i - 1] == s2[j - 1]) mem[i][j][k] = 1;
                    }
                    else {
                        for (int h = 1; h < k; h++)
                            mem[i][j][k] = mem[i][j][k] || mem[i][j + k - h][h] && mem[i + h][j][k - h] \
                            || mem[i][j][h] && mem[i + h][j + h][k - h];
                    }

                }
            }
        }
        return mem[1][1][n];
    }
};