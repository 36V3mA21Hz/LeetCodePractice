class Solution {
public:
    int totalNQueens(int n) {
        int output = 0;
        pickPos({}, n, 0, output);
        return output;
    }
    void pickPos(vector<int> buffer, int &n, int level, int &output) {
        if (level >= n) {
            output++;
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
                pickPos(buffer, n, level+1, output);
            }
            buffer = savor;
        }
    }
    
};
