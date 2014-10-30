class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	if (digits.empty()) return {};
    	int carry = 1;
    	for (int i = digits.size() - 1; i >= 0; i--) {
    		carry = (digits[i] + carry) / 10;
            digits[i] = (digits[i] + carry) % 10;
    	}
    	if (carry)
    		digits.insert(digits.begin(), 1);
    	return digits;
    }
};