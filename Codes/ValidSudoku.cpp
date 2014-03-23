class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
    	vector<int> judgeTool1(9, 0);
    	vector<int> judgeTool2(9, 0);
    	vector<int> judgeTool3(9, 0);
    	for (int i = 0; i < 9; i++) {
    		for (int j = 0; j < 9; j++) {
    			int e1, e2;
    			if (board[i][j] == '.')
    				continue;
    			else
    				e1 = (int)board[i][j];
    			if (board[j][i] == '.')
    				continue;
    			else
    				e2 = (int)board[j][i];
    			judgeTool1[e1]++;
    			judgeTool2[e2]++;
    		}
    		for (auto it = judgeTool1.begin(); it != judgeTool1.end(); it++) {
    			if (*it >= 2)
    				return false;
    		}
    		judgeTool1.clear();
    		for (auto it = judgeTool2.begin(); it != judgeTool2.end(); it++) {
    			if (*it >= 2)
    				return false;
    		}
    		judgeTool2.clear();
    	}
    	for (int mul1 = 0; mul1 < 2; mul1++) {
    		for (int mul2 = 0; mul2 < 2; mul2++) {
	    		for (int i = mul1*3; i < 3 + mul1*3; i++) {
	    			for (int j = mul2*3; j < 3 + mul2*3; j++) {
	    				int e3;
		    			if (board[i][j] == '.')
		    				continue;
		    			else
		    				e3 = (int)board[i][j];
		    			judgeTool3[e3]++;
	    			}
	    		}
	    		for (auto it = judgeTool3.begin(); it != judgeTool3.end(); it++) {
                    if (*it >= 2)
                        return false;
    			}
	    	}
    	}
        return true;
    }
};