class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            new_string = ''
            
            for i in range(0, len(s), k):
                temp = 0
                
                for n in s[i : i + k]:
                    temp += int(n)

                new_string += str(temp)

            s = new_string
        return s

        