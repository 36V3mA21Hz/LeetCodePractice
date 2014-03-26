class Solution {
public:
	typedef vector<int>::iterator vit;
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> net;
        vit gi = gas.begin(), ci = cost.begin();
        int sum = 0;
        for (;gi != gas.end(); gi++, ci++) {
        	int temp = *gi - *ci;
        	sum += temp;
        	net.push_back(temp);
        }
        if (sum < 0)
        	return -1;
        int n = (int)net.size();
        vector<int>rems(n, 0);
        int index = -1;
        for (int i = 0; i < n; i++) {
            int j = i, c = 0;
            while (c < n) {
                if (rems[i] + net[j % n] >= 0)
                    rems[i] += net[j % n];
                else
                    rems[i] = -1;
                j++;
                c++;
            }
            if (rems[i] >= 0 && sum - rems[i] >= 0)
                index = i;
        }
        
        return index;
    }
};
