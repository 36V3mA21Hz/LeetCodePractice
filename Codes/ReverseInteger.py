class Solution:
    # @return an integer
    def reverse(self, x):
        y, z = 0, x
        if z < 0:
        	x = -x
        while x != 0:
        	y = y * 10 + x % 10
        	x = x // 10
        if z < 0:
        	y = -y
        return y