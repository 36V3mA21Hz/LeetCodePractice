class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
    	if (n == 0)
    		return {};
    	vector<int> initRow(n, 0);
    	vector<vector<int> > buffer(n, initRow);
    	vector<vector<string> > output;
    	pickPos(buffer, output, n, 0);
    	return output;
    }
    void pickPos(vector<vector<int> > buffer, vector<vector<string> > &output, int &n, int level) {
    	if (level >= n) {
            vector<string> temp;
    		for (auto row = buffer.begin(); row != buffer.end(); row++){
                string tempRow;
    			for (auto col = (*row).begin(); col != (*row).end(); col++) {
    				if (*col == 2)
    					tempRow.push_back('Q');
    				else
    					tempRow.push_back('.');
    			}
                temp.push_back(tempRow);
    		}
    		output.push_back(temp);
    		return;
    	}
        vector<vector<int> > savor;
    	for (int i = 0; i < n; i++) {
            savor = buffer;
    		if (!buffer[level][i]) {
    			buffer[level][i] = 2;
	    		int bufColL = i, bufColR = i;
	    		for (int bufRow = level+1; bufRow < n; bufRow++) {
	    			if (--bufColL >= 0)
	    				buffer[bufRow][bufColL] = 1;
	    			if (++bufColR < n)
	    				buffer[bufRow][bufColR] = 1;
	    			buffer[bufRow][i] = 1;
	    		}
	    		pickPos(buffer, output, n, level+1);
    		}
            buffer = savor;
    	}
    }
    
};