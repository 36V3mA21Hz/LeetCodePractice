class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if (num.empty())
        	return {};
        int n = num.size();
        vector<vector<int>> output;
        permuteUniqueAux(num, output, 0, n-1);
        return output;
    }
    void permuteUniqueAux(vector<int> &num, vector<vector<int>> &buffer, int i, int j) {
    	if (i == j){
    		buffer.push_back(num);
    		return;
    	}
    	for (int k = i; k <= j; k++) {
    		if (num[k] != num[i] || k == i) {
    			swap(num[k], num[i]);
    			permuteUniqueAux(num, buffer, i+1, j);
    			swap(num[k], num[i]);
    		}
    	}
    }
    void swap(int &a, int &b) {
    	int temp = a;
    	a = b;
    	b = temp;
    }
};