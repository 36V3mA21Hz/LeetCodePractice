class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty())
        	return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > output;
        int n = (int)candidates.size();
        for (int i = 0; i < n; i++) {
        	vector<int> phi;
            phi.push_back(candidates[i]);
            combinationAux(candidates, output, phi, target, candidates[i], i, n);
        }
        return output;
    }
    void combinationAux(vector<int> &cands, vector<vector<int> > &buffer, vector<int> temp, int &target, int sum, int i, int &n) {
        vector<int> savor = temp;
        int sumSavor = sum;
         if (sum == target) {
            buffer.push_back(temp);
            return;
        } else if (sum > target) {
            return;
        } else if (sum < target) {
            sum += cands[i];
            temp.push_back(cands[i]);
            combinationAux(cands, buffer, temp, target, sum, i, n);
        }
        i++;
        temp = savor;
        sum = sumSavor;
        while (i < n) {
            sum += cands[i];
            temp.push_back(cands[i]);
            combinationAux(cands, buffer, temp, target, sum, i, n);
            temp = savor;
            sum = sumSavor;
            i++;
        }
    }
};
