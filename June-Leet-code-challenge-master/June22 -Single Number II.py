class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        b1, b0 = 0, 0
        for num in nums:
            b0 = (b0 ^ num) & (~b1)
            b1 = (b1 ^ num) & (~b0)
        return b0
