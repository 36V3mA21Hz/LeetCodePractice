class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.empty())
            return 0;
        if (num.size() == 1)
            return num[0];
        else if (num.size() == 2)
            return num[0] + num[1];
        sort(num.begin(), num.end());
        int n = (int)num.size(), twoSum = 0, closeSum = 0;
        int left = 0, right = n - 1;
        while (left < right - 1) {
            twoSum = num[left] + num[right];
            int diffMin = INT_MAX;
            for (int i = left + 1; i < right; i++) {
                if (abs(twoSum + num[i] - target) < diffMin) {
                    closeSum = twoSum + num[i];
                    diffMin = abs(closeSum - target);
                }

            }
            if ((left + right) % 2)
                left++;
            else
                right--;
        }
        return closeSum;
    }
};