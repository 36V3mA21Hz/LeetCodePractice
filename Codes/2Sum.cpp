class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mymap;
        int n = (int)numbers.size();
        for (int i = 0; i < n; i++) {
            mymap[numbers[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            int counterpart = target - numbers[i];
            auto got = mymap.find(counterpart);
            if (got != mymap.end()) {
                if (got->second != i)
                    return {i + 1, got->second + 1};
            }
        }
        return {};
    }
};