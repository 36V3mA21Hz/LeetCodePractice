class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if (num.empty())
        	return {};
        sort(num.begin(), num.end());
        int n = (int)num.size();
        vector<vector<int> > output;
        for (int i = 0; i < n; i++) {
            if (i > 0)
                if (num[i-1] == num[i])
                    continue;
        	int j = i + 1;
        	int k = n - 1;
        	while (j < k) {
                if (j - i >= 2) {
                    if (num[j-1] == num[j]) {
                        j++;
                        continue;
                    }
                }
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    output.push_back({num[i], num[j], num[k]});
                    j++;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
        	}
        }
        return output;
    }
};
