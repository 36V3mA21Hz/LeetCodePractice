class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int leftBase = 1;
        int y = x / 10;
        while (y) {
        	y /= 10;
        	leftBase *= 10;
        }
        int rightBase = 1;
        y = x;
        int right = x % 10, left = y / leftBase;
        while (leftBase > rightBase) {
        	if (left != right)
        		return false;
        	y -= left * leftBase;
        	leftBase /= 10;
        	left = y / leftBase;
			x = (x - right) / 10;
			rightBase *= 10;
			right = x % 10;
        }
        return true;
    }
};
