class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        y = 0
        for x in A:
            y ^= x
        return y
            