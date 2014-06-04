class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int m = (int)S.size(), n = (int)L.size(), k = L[0].size();
        if (S.empty() || L.empty() || m < k * n)
            return{};
        vector<int> output;
        unordered_map<string, int> map1, map2;
        for (int i = 0; i < n; i++) {
            map1[L[i]]++;
        }
        for (int i = 0; i < m - n * k + 1; i++) {
            bool found = true;
            map2.clear();
            for (int j = i; j < i + n * k; j += k) {
                string temp(S, j, k);
                auto got = map1.find(temp);
                if (got != map1.end()) {
                    map2[temp]++;
                }
                else {
                    found = false;
                    break;
                }
                if (map2[temp] > map1[temp]) {
                    found = false;
                    break;
                }

            }
            if (found)
                output.push_back(i);
        }
        return output;
    }
};