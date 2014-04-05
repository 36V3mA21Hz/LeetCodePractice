class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.empty())
        	return {};
        sort(num.begin(), num.end());
        vector<vector<int> > output;
        int n = (int)num.size();
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (num[i-1] == num[i]) {
                    continue;
                }
            }
        	for (int j = i + 1; j < n; j++) {
        		if (j - i > 1) {
        			if (num[j] == num[j - 1]) {
        				continue;
        			}
        		}
        		int k = j + 1;
        		int l = n - 1;
        		while (k < l) {
        			if (k - j > 1) {
        				if (num[k] == num[k - 1]) {
        					k++;
        					continue;
        				}
        			}
        			int sum = num[i] + num[j] + num[k] + num[l];
        			if (sum == target) {
        				output.push_back({num[i], num[j], num[k], num[l]});
                        k++;
        			} else if (sum > target)
        				l--;
        			else
        				k++;
        		}
        	}
        }
        return output;
    }
};
