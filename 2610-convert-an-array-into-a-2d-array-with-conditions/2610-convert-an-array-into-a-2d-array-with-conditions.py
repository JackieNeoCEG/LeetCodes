class Solution(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #keep track of the count of each unique integer
        count = defaultdict(int)
        res = []
        
        for n in nums:
            #no. of arrays needed based on the count
            row = count[n]
            if len(res) == row: #start a new row to prevent out-of-bounds error
                res.append([])
                
            res[row].append(n) #add current integer to array
            count[n] += 1
        return res
        