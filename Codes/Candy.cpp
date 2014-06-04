class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty())
        	return 0;
        int n = (int)ratings.size();
        vector<int> nums(n);
        nums[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                nums[i] = nums[i-1] + 1;
            } else {
                nums[i] = 1;
            }
        }
        int sum = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            int peakContrary = 1;
            if (ratings[i] > ratings[i+1]) {
                peakContrary = nums[i+1] + 1;
            }
            nums[i] = max(nums[i], peakContrary);
            sum += num[i];
        }
        return sum;
};