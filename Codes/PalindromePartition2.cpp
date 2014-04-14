class Solution {
public:
    int minCut(string s) {
    	if (s.empty())
    		return 0;
    	int n = (int)s.size();
    	vector<int> rems(n, 0);
        vector<int> row(n, 1);
        vector<vector<int>> palindrome(n, row);
    	for (int i = 0; i < n; i++) {
            int q = i;
            for (int k = i - 1; k >= 0; k--) {
                if (k >= i - 3 && s[k+1] == s[i]) {
                    q = min(q, rems[k] + 1);
                    palindrome[k+1][i] = 0;
                } else if (k < i - 3 && s[k+1] == s[i] && !palindrome[k+2][i-1]) {
                    q = min(q, rems[k] + 1);
                    palindrome[k+1][i] = 0;
                } else {
                    palindrome[k+1][i] = 1;
                }
            }
            if (i < 2 && s[0] == s[i]) {
                q = 0;
                palindrome[0][i] = 0;
            } else if (i >= 2 && s[0] == s[i] && !palindrome[1][i-1]) {
                q = 0;
                palindrome[0][i] = 0;
            }
            rems[i] = q;
    	}
    	return rems[n-1];
    }
};
