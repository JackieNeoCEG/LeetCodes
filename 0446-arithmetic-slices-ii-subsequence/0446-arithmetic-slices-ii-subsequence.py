class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #idea to use 2D dp[i][j]
        totalCount = 0  
        n = len(nums)
    
        dp = [defaultdict(int) for _ in range(n)]
        
        #subsequence at index i with difference of j
        for i in range(1, n):
            for j in range(i):
                diff = nums[i] - nums[j]
                dp[i][diff] += 1  #update new arithmetic sequence with difference of diff
                
                #Case: existing subsequence at j also have difference of diff
                if diff in dp[j]:
                    dp[i][diff] += dp[j][diff]
                    totalCount += dp[j][diff]

        return totalCount