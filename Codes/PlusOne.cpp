class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	if (digits.empty()) return {};
    	int carry = 0;
    	for (auto it = digits.end() - 1; it >= digits.begin(); it--) {
    		if (it == digits.end() - 1) {
    			if (*it + 1 == 10) {
    				carry = 1;
    				*it = 0;
    			} else {
    				(*it)++;
    			}
    		} else {
    			if (*it + carry == 10) {
    				carry = 1;
    				*it = 0;
    			} else {
    				*it += carry;
    				carry = 0;
    			}
    		}
    	}
    	if (carry == 1)
    		digits.insert(digits.begin(), 1);
    	return digits;
    }
};