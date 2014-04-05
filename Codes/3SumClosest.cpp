class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.empty())
            return 0;
        sort(num.begin(), num.end());
        int n = (int)num.size(), closeSum = 0, diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int tempSum = num[i] + num[j] + num[k];
                if (abs(tempSum - target) < diff) {
                    diff = abs(tempSum - target);
                    closeSum = tempSum;
                }
                if (tempSum < target)
                    j++;
                else
                    k--;
            }
        }
        return closeSum;
    }
};
