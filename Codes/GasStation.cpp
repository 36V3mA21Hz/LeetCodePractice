class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> between2Cites(gas.size());
        vector<int> from0ToCur(gas.size());
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            between2Cites[i] = gas[i] - cost[i];
            sum += between2Cites[i];
            from0ToCur[i] = sum;
        }
        for (int i = 0; i < from0ToCur.size(); i++) {
            if (from0ToCur[i] >= 0 && sum - from0ToCur[i] >= 0)
                return i;
        }
        return -1;
    }
};
