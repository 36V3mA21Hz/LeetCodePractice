class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty())
            return 0;
        map<int, int> map1;
        for (auto vit = num.begin(); vit != num.end(); vit++) {
            map1.insert(pair<int, int> (*vit, *vit));
        }
        int maxL = 1, curL = 1;
        auto mit = map1.begin();
        map<int, int>::iterator mit2 = mit;
        mit++;
        for (;mit != map1.end(); mit++) {
            if (mit->second == mit2->second + 1) {
                curL++;
            } else {
                maxL = maxL < curL ? curL : maxL;
                curL = 1;
            }
            mit2 = mit;
        }
        maxL = maxL < curL ? curL : maxL;
        return maxL;
    }
};
