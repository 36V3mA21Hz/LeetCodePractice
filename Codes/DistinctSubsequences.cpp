class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int>row(S.size() + 1, 0);
        vector<vector<int>>times(T.size() + 1, row);
        
        for (int i = 0; i <= T.size(); i++) {
            times[i][0] = 0;
        }
        for (int j = 0; j <= S.size(); j++) {
            times[0][j] = 1;
        }
        for (int i = 1; i <= T.size(); i++) {
            for (int j = 1; j <= S.size(); j++) {
                if (T[i - 1] == S[j - 1])
                    times[i][j] = times[i-1][j-1] + times[i][j-1];
                else
                    times[i][j] = times[i][j-1];
            }
        }
        return times[T.size()][S.size()];
    }
};
