class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = nums
        index = 0;
        
        for num in nums:
            nums[index] = num * num
            index += 1
        
        res.sort()
        return res