class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor)
            return INT_MAX;
        unsigned y2 = abs(dividend), x2 = abs(divisor);
        unsigned long long y = y2, x = x2;
        bool neg = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            neg = true;
        unsigned long long sum = 0, quo = 0;
        while (sum < y) {
            unsigned long long temp = x;
            int j = 0;
            while (sum + temp <= y) {
                j++;
                temp = temp << 1;
            }
            if (j) {
                sum += temp >> 1;
                quo += 1 << --j;
            } else  {
                break;
            }
        }
        int result = (int)quo;
        if (neg)
            return -result;
        else
            return result;
    }
};