class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int>> output;
    	vector<int> v;
    	combineAux(1, k, n, v, output);
    	return output;
    }
    void combineAux(int l, int k, int n, vector<int> v, vector<vector<int>> &buffer) {
    	if (k == 0) {
    		buffer.push_back(v);
    		return;
    	}
    	for (int i = l; n - i >= k; i++) {
    		v.push_back(i);
    		combineAux(i + 1, k - 1, n, v, buffer, store);
    		v.pop_back();
    	}
    }
};
