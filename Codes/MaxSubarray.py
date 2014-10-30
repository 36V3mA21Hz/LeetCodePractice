class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        if len(A) == 0:
            return 0
        maxSofar, maxAll = A[0], A[0]
        for x in A[1:]:
            if maxSofar < 0:
                maxSofar = x
            else:
                maxSofar += x
            if maxSofar > maxAll:
                maxAll = maxSofar
        return maxAll