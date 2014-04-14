class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
        	return 0;
        int n = (int)s.size();
        int maxv = INT_MIN, i = 0;
        while (i < n) {
        	int temp = closeParentheses(s, i, n);
        	maxv = max(temp > 0 ? temp: 0, maxv);
        }
        return maxv * 2;
    }
    int closeParentheses(string &s, int &i, int n) {
    	if (i >= n)
    		return 0;
    	if (s[i] == ')') {
    		return 1;
    	}
    	int maxv = 0；
    	while (s[i] == '(') {
    		i++;
    		int temp = closeParentheses(s, i, n);
    		maxv = max(temp > 0 ? temp : 0, maxv);
	    }	
    	return maxv;
    }
};