class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor)
        	return INT_MAX;
        int d1 = abs(dividend), d2 = abs(divisor);
        int que = 0, powers = 32;
        while (convert(powers, d2) > (long)d1) {
          	powers--;
        }
        if (divisor < 0 && dividend > 0 || dividend > 0 && divisor < 0)
        	que = - que;
        return que;
    }
    long convert(int powers, int d2) {
    	long temp = d2;
    	int bitPos = 0;
    	while (powers) {
    		if (1 & powers) 
    			temp += temp * 1 << bitPos;
    		powers = powers >> 1;
    	}
    	return temp;
    }
};