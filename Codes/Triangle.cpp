class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
            return 0;
        int n = (int)triangle.size();
        vector<int> m(n, 0);
        for (int i = n - 1; i >= 0; i--) {
        	for (int j = 0; j < i + 1; j++) {
        		if (i == n - 1)
        			m[j] = triangle[i][j];
        		else
        			m[j] = min(m[j], m[j+1]) + triangle[i][j];
        	}
        }
        return m[0];
    }
};
