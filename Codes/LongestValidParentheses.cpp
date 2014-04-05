class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
        	return 0;
        int n = (int)s.size();
        int maxv = INT_MIN, i = 0, result = 0;
        while (i < n) {
        	result += closeParentheses(s, i, n);
        }
        return result * 2;
    }
    int closeParentheses(string &s, int start, int n) {
    	int i = start, pairs = 0, levels = 0;
    	if (s[i] == '(')
    		levels++;
    	i++;
    	while(levels != 0 && i < n) {
    		if (s[i] == '(')
    			levels++;
    		else {
    			levels--;
    			pairs++;
    		}
    		i++;
    	}
    	if (levels != 0)
    		pairs = 0;
    	return pairs;
    }
};