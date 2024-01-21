class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        rob, norob = 0, 0
        
        for num in nums:
            newRob = norob + num
            newNoRob = max(norob, rob)
            rob, norob = newRob, newNoRob
            
        return max(rob, norob)