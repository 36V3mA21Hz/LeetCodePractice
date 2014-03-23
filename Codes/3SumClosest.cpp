class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int sum = 0;
        if (num.size() <= 3) {
            for (auto it = num.begin(); it != num.end(); it++)
                sum += *it;
            return sum;
        }
        sort(num.begin(), num.end());
        sum = num[0] + num[1] + num[2];
        int i = 3;
        while (sum < target) {
            sum += num[i++];
        }
        sum = findSum(num, i, target);
        return sum;
    }
    
    int findSum(vector<int> &num, int n, int target) {
        int diff = INT_MAX;
        int sum, temp;
        for (int i = 0; i < n -2 ; i++) {
            for (int j = 1; j < n - 1; j++) {
                for (int k = 2; k < n; k++) {
                    temp = num[i] + num[j] + num[k];
                    if (abs(temp - target) < diff) {
                        sum = temp;
                        diff = abs(sum - target);
                    }
                }
            }
        }
        return sum;
    }
};
