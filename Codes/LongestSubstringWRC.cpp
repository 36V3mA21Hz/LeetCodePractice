class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
        	return 0;
        
        int len = 1;
        for (auto it = s.begin(); it != s.end(); it++) {
            unordered_set<char> temp;
            temp.insert(*it);
            bool dup = false;
            for (auto it2 = it + 1; it2 != s.end(); it2++) {
                if (temp.find(*it2) == temp.end())
                    temp.insert(*it2);
                else {
                    dup = true;
                    len = (int)temp.size() > len ? (int)temp.size() : len;
                    break;
                }
                if (!dup)
                    len = (int)temp.size() > len ? (int)temp.size() : len;
            }
        }
        return len;
    }
};
