class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        if (strs.empty())
            return {};
        vector<string> output;
        vector<int> dup(26, 0);
        vector<vector<int>> dups(strs.size(), dup);
        for (auto it = strs.begin(); it != strs.end(); it++) {
            for (auto si = (*it).begin(); si != (*it).end(); si++) {
                dups[it - strs.begin()][*si - 'a']++;
            }
        }
        unordered_map<int, unordered_set<int>> marks1;
        for (int j = 0; j < 26; j++) {
            if (marks1.empty()) {
                for (int i = 0; i < strs.size(); i++) {
                    auto got = marks1.find(dups[i][j]);
                    if (got == marks1.end()) {
                        unordered_set<int> pos({i});
                        marks1.insert({dups[i][j], pos});
                    } else {
                        got->second.insert(i);
                    }
                }
            } else {
                unordered_set<int> judge;
                for (auto it = marks1.begin(); it != marks1.end(); it++) {
                    for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
                        if (judge.empty())
                            judge.insert(dups[*jt][j]);
                        auto got = judge.find(dups[*jt][j]);
                        if (got == judge.end())
                            it->second.erase(jt);
                    }
                }
            }
        }
        if (marks1.size() > 1)
            return {};
        auto it = marks1.begin();
        for (auto jt = it->second.begin(); jt != it->second.end(); jt++) {
            output.push_back(strs[*jt]);
        }
        return output;
    }
};
