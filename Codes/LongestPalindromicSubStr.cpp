class Solution {
public:
     string longestPalindrome(string s) {
          if (s.empty())
               return "";
          int n = (int)s.size();
          bool p[1000][1000] = { false };
          for (int i = 0; i < n; i++) {
               p[i][i] = true;
          }
          int start = 0, maxlength = 1;
          for (int j = 1; j < n; j++) {
               for (int i = j - 1; i >= 0; i--) {
                    if ((p[i + 1][j - 1] || i == j - 1) && s[i] == s[j]) {
                         p[i][j] = true;
                         if (maxlength < j - i + 1)
                              start = i, maxlength = j - i + 1;
                    }
               }
          }
          return s.substr(start, maxlength);
     }
};