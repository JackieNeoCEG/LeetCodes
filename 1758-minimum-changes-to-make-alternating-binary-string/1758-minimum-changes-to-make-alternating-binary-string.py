class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        
        for i in range(len(s)):
            if i % 2: #odd
                count += 1 if s[i] == "0" else 0
            else: #even
                count += 1 if s[i] == "1" else 0
        return min(count, len(s) - count)
        