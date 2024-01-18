class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        if not cost:
            return 0;
        
        dp = [0] * len(cost)
        
        dp[0] = cost[0]
        dp[1] = cost[1] #since cost[0] + cost[1] will always be bigger
        #dp[2] = cost[2] + min(dp[1], dp[0]) is the next step, just iterate using loop
        
        for i in range(2, len(cost)):
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])
        
        return min(dp[len(dp) - 1], dp[len(dp) - 2])
        
        
        