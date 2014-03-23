class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	if (num.empty()) return {};
    	int n = num.size();
    	vector<vector<int>> output;
        permuteAux(num, 0, n - 1, output);
        return output;

    }
    void permuteAux(vector<int> &num, int i, int j, vector<vector<int>> &buffer) {
        if (i == j)
            buffer.push_back(num);
        else {
            for (int k =i; k <= j; k++) {
                swap(num[i], num[k]);
                permuteAux(num, i+1, j, buffer);
                swap(num[i], num[k]);
            }
        }
    }
    void swap(int &i, int &j) {
        int temp = i;
        i = j;
        j = temp;
    }
}; 