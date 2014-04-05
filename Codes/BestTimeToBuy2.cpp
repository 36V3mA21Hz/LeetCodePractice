class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;
    	int n = (int)prices.size();
        int max = 0;
    	vector<int> profits(n);
        profits[0] = 0;
        for (int i = 1; i < n; i++) {
            profits[i] = prices[i] - prices[i-1];
        }
        for (int i = 0; i < n; i++) {
            if (profits[i] > 0)
                max += profits[i];
        }
    	return max;
    }
};