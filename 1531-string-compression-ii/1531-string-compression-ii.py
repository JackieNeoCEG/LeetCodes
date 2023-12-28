class Solution(object):
    def getLengthOfOptimalCompression(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        cache = {} #hashmap for memoization: storing results for faster access
        
        #recursive function
        def count(i, k, prev, consecutive_count): #consecutive_count is the no of repeat characters 
            if (i, k, prev, consecutive_count) in cache:
                return cache[(i, k, prev, consecutive_count)]
            if k < 0:
                return float('inf') 
            
            if i == len(s):
                return 0
            
            #same characters
            if s[i] == prev: 
                #example case: 99 -> 100, is 3 characters
                increment = 1 if consecutive_count in [1, 9, 99] else 0
                res = increment + count(i + 1, k, prev, consecutive_count + 1)
                
            #different characters    
            else:
                res = min(
                    count(i + 1, k - 1, prev, consecutive_count), #delete s[i]
                    1 + count(i + 1, k, s[i], 1) #dont delete 
                )
                
            cache[(i, k, prev, consecutive_count)] = res
            return res
        
        return count(0, k, "", 0)
        