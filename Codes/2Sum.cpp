class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if (numbers.empty())
            return {};
        int n = (int)numbers.size();
        int i = 0, j = n - 1;
        unordered_map<int, int> mymap;
        for (int k = 0; k < n; k++) {
            pair<int, int> temp(numbers[k], k);
            mymap.insert(temp);
        }
        sort (numbers.begin(), numbers.end());
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                auto g1 = mymap.find(numbers[i]);
                auto g2 = mymap.find(numbers[j]);
                if (g1->second < g2->second)
                    return {g1->second + 1, g2->second + 1};
                else
                    return {g2->second + 1, g1->second + 1};
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
