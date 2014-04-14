class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor)
        	return INT_MAX;
        int k = 0, n = 0, d1 = abs(dividend), d2 = abs(divisor);
        int temp = d2, que = 0, lower = 0, upper = 0;
        while (temp <= d1) {
        	if (temp > d1) {
        		temp = temp >> 1;
        		upper--;
        	} else {
        		temp = temp << 1;
        		upper++;
        	}
        }
        if (divisor < 0 && dividend > 0 || dividend > 0 && divisor < 0)
        	que = - que;
        return que;
    }
};