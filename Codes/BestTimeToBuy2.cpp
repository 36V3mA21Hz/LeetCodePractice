class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int n = prices.size();
    	int low = INT_MAX;
    	int high = INT_MIN;
    	int profit = 0;
    	bool bought = false;
    	for (int i = 0; i < n; i++) {
    		if (prices[i] <= low && !bought) {
    			low = prices[i];
    		}
    		if (prices[i] > low && !bought) {
    			bought = true;
    		}
    		if (prices[i] >= high && bought) {
    			high = prices[i];
    		}
    		if (prices[i] < high && high > low && bought) {
    			bought = false;
    			profit += high - low;
    			low = INT_MAX;
    			high = INT_MIN;
    		}
            if (i == n -1 && bought && high > low) {
                bought = false;
    			profit += high - low;
    			low = INT_MAX;
    			high = INT_MIN;
            }
            if (prices[i] <= low && !bought) {
    			low = prices[i];
    		}
    		if (prices[i] > low && !bought) {
    			bought = true;
    		}
    	}
    	return profit;
    }
};