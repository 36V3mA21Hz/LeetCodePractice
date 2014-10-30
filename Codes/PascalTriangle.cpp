class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		if (numRows == 0) return{};
		vector<vector<int>> pascal(numRows, vector<int>());
		pascal[0].push_back(1);
		for (int j = 1; j < numRows; j++) {
			for (int i = 0; i < j + 1; i++) {
				int x;
				if (i != 0 && i != j)
					x = pascal[j - 1][i] + pascal[j - 1][i - 1];
				else
					x = 1;
				pascal[j].push_back(x);
			}
		}
		return pascal;
	}
};