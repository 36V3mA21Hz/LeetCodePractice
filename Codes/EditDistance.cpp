class Solution {
public:
	typedef string::iterator sit;
    int minDistance(string word1, string word2) {
    	
        int m = (int)word1.size(), n = (int)word2.size();
    	vector<int> costRow(n + 1, 0);
    	vector<vector<int> > costs(m + 1, costRow);
        for (int i = 0; i < m + 1; i++)
            costs[i][0] = i;
        for (int i = 0; i < n + 1; i++)
            costs[0][i] = i;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n+ 1; j++) {
                if (word1[i-1] == word2[j-1]) {
                    costs[i][j] = costs[i-1][j-1];
                } else {
                    if (costs[i-1][j] > costs[i][j-1])
                        costs[i][j] = costs[i][j-1] + 1;
                    else if (costs[i-1][j] < costs[i][j-1])
                        costs[i][j] = costs[i-1][j] + 1;
                    else
                        costs[i][j] = costs[i-1][j-1] + 1;
                }
            }
        }
    	return costs[m][n];
    }
};