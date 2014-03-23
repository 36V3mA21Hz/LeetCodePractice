class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
        int iter;
    	for (int i = start; i < S.size(); i++) {
            temp = savor;
            temp.push_back(S[i]);
            if (i > 0) {
                if (temp.back() == iter)
                    continue;
            }
    		buffer.push_back(temp);
    		subsetsAux(buffer, temp, S, i+1);
            iter = temp.back();
    	}
    }
};