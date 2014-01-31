class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty())
        	return 0;
        vector<int> record(triangle.size(), -1);
        return minPath(triangle, 0, 0);
    }
    int minPath(vector<vector<int>> &triangle, vector<int> &record, int index, int level) {
    	if (record[level] != -1) {
    		index = record[level];
    		return triangle[level][index];
    	}
    	if (index < 0 || index >= triangle[level].size())
    		return INT_MAX;
        if (level >= triangle.size())
            return 0;
        int q = INT_MAX;
        int indexSavor = index;
        for (int i = index - 1; i <= index + 1; i++) {
            int temp = minPath(triangle, i, level + 1);
            if (temp < q) {
            	q = temp;
            	indexSavor = i;
            } 
        }
        record[level] = indexSavor;
        return q + triangle[level][index];
    }
};