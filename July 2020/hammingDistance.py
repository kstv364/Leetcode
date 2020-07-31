class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        ans = x^y
        b = bin(ans)[2:]
        return b.count('1')