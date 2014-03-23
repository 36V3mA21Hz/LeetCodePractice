class Solution {
public:
    string addBinary(string a, string b) {
    	string c;
    	int ia = 0, ib = 0, carry = 0;
    	auto ita = a.end() - 1;
    	auto itb = b.end() - 1;
    	while (ita >= a.begin() || itb >= b.begin() || carry != 0) {
    		if (ita >= a.begin()) {
    			ia = (*ita) - '0';
    			ita--;
    		} else {
    			ia = 0;
    		}
    		if (itb >= b.begin()) {
    			ib = (*itb) - '0';
   				itb--;
    		} else {
    			ib = 0;
    		}
    		if (ia + ib + carry >= 2) {
       			c.insert(c.begin(), '0' + ia + ib + carry - 2);
       			carry = 1;
    		} else {
    			c.insert(c.begin(), '0' + ia + ib + carry);
    			carry = 0;
    		}
    	}
    	return c;
    }
};
