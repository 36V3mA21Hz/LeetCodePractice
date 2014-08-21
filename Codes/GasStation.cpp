class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0, totalGas = 0, startPoint = 0, n = gas.size(), diff = 0;
        for (int i = 0; i < n; i++) {
            diff = gas[i] - cost[i];
            totalGas += diff;
            sum += diff;
            if (sum < 0) {
                startPoint = i + 1;
                sum = 0;
            }
        }
        if (totalGas < 0)
            return -1;
        return startPoint;
    }
};
