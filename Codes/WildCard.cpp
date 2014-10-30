class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *asterisk = NULL;
        const char *ss = s;
        while (*s) {
            if (*p == '?' || *p == *s) 
                s++, p++;
            else if (*p == '*')
                asterisk = p++, ss = s;
            else if (asterisk)
                p = asterisk + 1, s = ++ss;
            else
                return false;
        }
        while (*p == '*')
            p++;
        return !*p;
    }
};