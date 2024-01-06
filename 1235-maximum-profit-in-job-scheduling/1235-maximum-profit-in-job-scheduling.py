class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
        #Thought Process: Memoisation over Greedy as best decision can't be made without scanning
        #zip combines elements from arrays into tuples
        
        # Combine start times, end times, and profits into tuples and sort them based on start time
        # to maintain order after sorting
        interval = sorted(zip(startTime, endTime, profit)) #= [[],[],[]]
        cache = {}
        
        def dfs(i):
            if i == len(interval): #out-of_bounds
                return 0
            if i in cache:
                return cache[i] # Return the memoized result
            
            #dont include at index i
            res = dfs(i + 1)
            
            #include at index i
            #Use binary search to find the next non-overlapping interval
            j = bisect.bisect(interval,(interval[i][1], -1, -1)) #-1 trick to let the binary search endTime only
            cache[i] = res = max(res, interval[i][2] + dfs(j)) 
            return res
        
        return dfs(0)