class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int>> output;
    	stack<vector<int>> store;
    	vector<int> v;
    	vector<int> num;
    	for (int i = 1; i <= n; i++)
    		num.push_back(i);
    	combineAux(num, 0, k, n, v, output, store);
    	return output;
    }
    void combineAux(vector<int> &num, int l, int k, int n, vector<int> v, vector<vector<int>> &buffer, stack<vector<int>> &store) {
    	if (k == 0) {
    		buffer.push_back(v);
    		return;
    	}
    	for (int i = l; n - i >= k; i++) {
    		store.push(v);
    		v.push_back(num[i]);
    		combineAux(num, i + 1, k - 1, n, v, buffer, store);
    		v = store.top();
    		store.pop();
    	}
    }
};
