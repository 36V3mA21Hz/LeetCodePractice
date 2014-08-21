class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, curLen = 0;
        int chars[256] = {-1};
        for (int i = 0; i < (int)s.size(); i++) {
            if (chars[s[i]] == -1) {
                chars[s[i]] = i;
                curLen++;
            } else {
                maxLen = max(maxLen, curLen);
                curLen = i - chars[s[i]];
                chars[s[i]] = i;
            }
        }
        return maxLen;
    }
};
