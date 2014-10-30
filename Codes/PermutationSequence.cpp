class Solution {
public:
    string getPermutation(int n, int k) {
        if (n < 2) 
        	return "1";
        int digit = n;
        while (!k) {
        	while (k - factorial(digit) < 0) {
        		digit--;
        	}
        	int 
        }
    }
};