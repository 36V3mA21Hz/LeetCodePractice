class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> m(s.size() + 1, false);
        m[0] = true;
        for (int i = 1; i <= s.size(); i++) {
        	for (int j = i; j >= 1; j--) {
        		if (m[j-1] && dict.find(s.substr(j-1, i-j+1)) != dict.end())
        			m[i] = true;
        	}
        }
        return m[s.size()];
    }
};