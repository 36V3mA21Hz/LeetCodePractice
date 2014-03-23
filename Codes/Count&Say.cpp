class Solution {
public:
    string countAndSay(int n) {
    	if (n == 0)
    		return "";
    	string cur;
    	string last;
    	last.push_back('0' + 1);
    	for (int i = 2; i <= n; i++) {
    		cur.clear();
    		char c = last.front();
    		int cout = 0;
    		for (int j = 0; j < last.size(); j++) {
                if (j != last.size() - 1) {
                    if (c == last[j]) {
                        cout++;
                    } else {
                        cur.push_back('0' + cout);
                        cur.push_back(c);
                        c = last[j];
                        cout = 1;
                    }
                } else {
                    if (c == last[j]) {
                        cur.push_back('0' + cout + 1);
                        cur.push_back(c);
                    } else {
                        cur.push_back('0' + cout);
                        cur.push_back(c);
                        cur.push_back('0' + 1);
                        cur.push_back(last[j]);
                    }
                }
    		}
    		last = cur;
    	}
    	return last;
    }
};
