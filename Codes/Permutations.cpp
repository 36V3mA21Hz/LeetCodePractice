class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	if (num.empty()) return {};
    	int n = num.size();
    	vector<int> blank;
    	vector<vector<int>> output;

    }
    vector<vector<int> > permuteAux(vector<int> &num, int l, int r) {
    	if (l > r) return {};
    	vector<vector<int>> output;
    	if (l == r) return output
    	
    	return permuteAux(num, l)

    }
};