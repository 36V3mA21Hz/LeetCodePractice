class Solution {
    typedef unordered_set<int>::iterator usit;
    typedef unordered_map<int, int>::iterator umit;
public:
    vector<string> anagrams(vector<string> &strs) {
        if (strs.empty())
            return{};
        vector<string> output;
        unordered_set<int> curr, next;
        vector<int> dup(strs.size(), 0);
        vector<vector<int>> dups(26, dup);
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                dups[strs[i][j] - 'a'][i]++;
                next.emplace(i);
            }
        }
        for (int i = 0; i < 26; i++) {
            curr = next;
            next.clear();
            unordered_map<int, int> temp;
            for (usit j = curr.begin(); j != curr.end(); j++) {
                umit got = temp.find(dups[i][*j]);
                if (got == temp.end()) {
                    temp.emplace(dups[i][*j], *j);
                }
                else {
                    if (next.find(got->second) != next.end()) {
                        next.emplace(*j);
                    }
                    else {
                        next.emplace(got->second);
                        next.emplace(*j);
                    }
                }
            }
        }
        for (usit i = next.begin(); i != next.end(); i++)
            output.push_back(strs[*i]);
        return output;
    }
};
