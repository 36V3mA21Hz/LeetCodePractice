class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        int maxLen = 0;
        vector<int> p(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '(') {
                int j = i + p[i + 1] + 1;
                if (j < n && s[j] == ')') {
                    p[i] = p[i + 1] + 2;
                    if (j + 1 < n)
                        p[i] += p[j + 1];
                }
            }
            maxLen = max(maxLen, p[i]);
        }
        return maxLen;
    }
};