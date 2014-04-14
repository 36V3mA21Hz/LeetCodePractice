class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
        	return 0;
        int n = (int)s.size();
        vector<int> rems(n);
        rems[0] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < n; i++) {
        	if (s[i] == '0') {
        		if (s[i-1] >= '1' && s[i-1] <= '2') {
        			if (i > 1)
                        rems[i] = rems[i-2];
                    else
                        rems[i] = 1;
        		} else {
        			break;
        		}
        	} else {
        		if ((s[i-1] == '1' && s[i] >= '1' && s[i] <= '9') || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6') ) {
                    if (i > 1)
                        rems[i] = rems[i-1] + rems[i-2];
                    else
                        rems[i] = rems[i-1] + 1;
        		} else {
        			rems[i] = rems[i-1];
        		}
        	}
        }
        return rems[n-1];
    }
};