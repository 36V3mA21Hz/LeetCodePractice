class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.empty())
            return 0;
        int n = (int)height.size();
        int maxA = 0, i = 0, j = n - 1;
        while (i < j) {
            if (height[i] < height[j]) {
                maxA = max(maxA, height[i] * (j - i));
                i++;
            }
            else {
                maxA = max(maxA, height[j] * (j - i));
                j--;
            }
        }
        return maxA;
    }
};