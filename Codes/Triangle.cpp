class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
        	return 0;
        vector<int> record(triangle.size()+1, -1);
        int q = INT_MAX;
        for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
        	int temp = minPath(triangle, record, i, triangle.size() - 1);
        	q = temp < q ? temp : q;
        }
        return q;
    }
    int minPath(vector<vector<int>> &triangle, vector<int> &record, int index, int level) {
        if (level >= triangle.size() || level < 0)
            return 0;
        if (index < 0 || index >= triangle[level].size())
    		return INT_MAX;
    	if (record[level] != -1) {
    		index = record[level];
    		return triangle[level][index];
    	}
    	int q = INT_MAX;
    	for (int i = index - 1; i <= index + 1; i++) {
    		if (i < 0 || i > triangle[level].size() - 1) continue;
    		q = q < triangle[level][i] ? q : triangle[level][i];
    	}
    	return q + minPath(triangle, record, index, level - 1);
    }
};
