class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
        	return 0;
        int n = (int)prices.size();
        vector<int> profits(n);
        profits[0] = 0;
        for (int i = 1; i < n; i++) {
        	profits[i] = prices[i] - prices[i-1];
        }
        int max1 = 0, maxSofar = 0, i1 = 0, j1 = 0, b = 0;
        for (int i = 0; i < n; i++) {
        	if (maxSofar > 0)
        		maxSofar += profits[i];
        	else {
        		maxSofar = profits[i];
        		b = i;
        	}
        	if (max1 < maxSofar) {
        		max1 = maxSofar;
        		j1 = i;
        		i1 = b;
        	}
        }
        int max2 = 0;
        maxSofar = 0, b = 0;
        for (int i = 0; i < n; i++) {
        	if (maxSofar > 0)
        		maxSofar += profits[i];
        	else {
        		maxSofar = profits[i];
        		b = i;
        	}
        	if (max2 < maxSofar) {
        		if (b > j1 || i < i1)
        			max2 = maxSofar;
                else
                    maxSofar = 0;
        	}
        }
        int min = 0, minSofar = 0;
        for (int i = i1; i <= j1; i++) {
        	if (profits[i] < 0)
        		minSofar += profits[i];
            else
                minSofar = 0;
        	if (min > minSofar)
        		min = minSofar;
        }
        int result = (max1 - min) > (max1 + max2) ? (max1 - min) : (max1 + max2);
        return result;
    }
};
