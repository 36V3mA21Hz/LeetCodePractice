class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        if (n == 0)
            return {};
        vector<int> buffer;
        vector<vector<string> > output;
        pickPos(buffer, output, n, 0);
        return output;
    }
    void pickPos(vector<int> buffer, vector<vector<string> > &output, int &n, int level) {
        if (level >= n) {
            vector<string> temp;
            for (auto it = buffer.begin(); it != buffer.end(); it++){
                string tempRow(n, '.');
                tempRow[*it] = 'Q';
                temp.push_back(tempRow);
            }
            output.push_back(temp);
            return;
        }
        vector<int> savor = buffer;
        bool fill;
        for (int i = 0; i < n; i++) {
            fill = true;
            for (int j = 0; j < level; j++) {
                if (i == buffer[j] || i == buffer[j]+(level-j) || i == buffer[j]-(level-j)) {
                    fill = false;
                    break;
                }
            }
            if (fill) {
                buffer.push_back(i);
                pickPos(buffer, output, n, level+1);
            }
            buffer = savor;
        }
    }
    
};
