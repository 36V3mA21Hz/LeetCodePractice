class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        if (strs.empty())
            return{};
        vector<string> output;
        unordered_map<string, int> myum;
        for (int i = 0; i < (int)strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            auto got = myum.find(temp);
            if (got == myum.end()) {
                myum.emplace(temp, i);
            }
            else {
                if (got->second != -1) {
                    output.push_back(strs[got->second]);
                    output.push_back(strs[i]);
                    got->second = -1;
                }
                else {
                    output.push_back(strs[i]);
                }
            }
        }
        return output;
    }
};