class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.empty())
            return 0;
        int temp = num[0];
        for (int i = 1; i < num.size(); i++) {
            if (temp > num[i])
                return num[i];
            else
                temp = num[i];
        }
        return num[0];
    }
};