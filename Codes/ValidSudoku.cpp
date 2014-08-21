class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> filled_t(9,false), filled;
        for (int i = 0; i < 9; i++) {
            filled = filled_t;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (filled[board[i][j] - '1']) {
                    return false;
                } else {
                    filled[board[i][j] - '1'] = true;
                }    
            }
        }
        for (int j = 0; j < 9; j++) {
            filled = filled_t;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (filled[board[i][j] - '1']) {
                    return false;
                } else {
                    filled[board[i][j] - '1'] = true;
                }    
            }
        }
        for (int rS = 0; rS < 3; rS++) {
            for (int cS = 0; cS < 3; cS++) {
                filled = filled_t;
                for (int i = rS * 3; i < rS * 3 + 3; i++) {
                    for (int j = cS * 3; j < cS * 3 + 3; j++) {
                        if (board[i][j] == '.') continue;
                        if (filled[board[i][j] - '1']) {
                            return false;
                        } else {
                            filled[board[i][j] - '1'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};