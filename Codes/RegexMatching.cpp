class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = s, *asterisk = NULL;
        const char *preChar = NULL;
        while (*s) {
        	if (*p == '.' || *s == *p)
        		s++, p++;
        	else if (*(p + 1) == '*') {
        		p += 2;
        		asterisk = p - 1;
        		ss = s;
        		preChar = p - 3;
        	}
        	else if (asterisk) {
        		if ()
        	}
        	else
        		return false;
        }
        while (*p == '*')
        	p++;
        return !*p;
    }
};