class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1)
        	return s;
        string newS;
        int n = (int)s.size();
        int diago = 2 * nRows - 2;
        for (int i = 0; i < nRows; i++) {
        	int j = i;
        	while (j < n && j >= 0) {
        		newS.push_back(s[j]);
        		if (diago < 2 * nRows - 2 && diago > 0 && j + diago < n) {
                    newS.push_back(s[diago + j]);
                }
                j += 2 * nRows - 2;
            }
            diago -= 2;
        }
        return newS;
            
    }
};
