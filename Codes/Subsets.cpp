class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        if (S.empty())
        	return {};
        sort(S.begin(), S.end());
        vector<vector<int> > output;
        output.push_back({});
        subsetsAux(output, {}, S, 0);
        return output;
    }
    void subsetsAux(vector<vector<int> > &buffer, vector<int> temp, vector<int> &S, int start) {
    	vector<int> savor = temp;
    	for (int i = start; i < S.size(); i++) {
    		temp = savor;
    		temp.push_back(S[i]);
    		buffer.push_back(temp);
    		subsetsAux(buffer, temp, S, i+1);
    	}
    }
};
