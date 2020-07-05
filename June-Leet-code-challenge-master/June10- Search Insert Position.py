class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        out=None
        for i in range(n):
            if nums[i]>=target:
                out = i
                break
        return n if out==None else out
