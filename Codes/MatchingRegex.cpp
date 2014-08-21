class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        char *i = s, *j = p;
        while (*i != '\0') {
        	if (*j != *i) {
        		if (*j == '\0')
        			return false;
        		/* ".*"" is always true */
        		else if (*j == '.' && *(j + 1) != '\0' && *(j + 1) == '*')
        			return true;
        		else if (*j == '.')
        			j++;
        		else if (*j == '*' && *(j - 1) == *i)
        		else
        			return false;
        	} else {
        		j++;
        	}
        	i++;
        }
        return true;
    }
};