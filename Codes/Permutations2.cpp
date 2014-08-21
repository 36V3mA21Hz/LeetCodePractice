class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if (num.empty())
            return{};
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int> > output;
        permuteUniqueAux(num, output, 0, n - 1);
        return output;
    }
    void permuteUniqueAux(vector<int> &num, vector<vector<int> > &buffer, int i, int j) {
        if (i == j){
            buffer.push_back(num);
            return;
        }
        for (int k = i; k <= j; k++) {
            int l = i;
            bool duplicate = false;
            while (l < k) {
                if (num[l++] == num[k]) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate || k == i) {
                swap(num[k], num[i]);
                permuteUniqueAux(num, buffer, i + 1, j);
                swap(num[k], num[i]);
            }
        }
    }
};