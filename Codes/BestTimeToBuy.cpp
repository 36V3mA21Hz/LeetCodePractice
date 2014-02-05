class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
    	int n = prices.size();
    	vector<int> diff;
        diff.push_back(0);
    	for (int i = 1; i < n; i++) {
    		diff.push_back(prices[i] - prices[i-1]);
    	}
    	int max_end = INT_MIN;
    	int max = INT_MIN;
    	for (int i = 0; i < n; i++) {
    		if (max_end > 0)
    			max_end += diff[i];
    		else
    			max_end = diff[i];
    		if (max < max_end)
    			max = max_end;
    	}
    	return max;
    }
};
