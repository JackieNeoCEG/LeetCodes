class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        count = 0
        for word in text.split():
            flag = False

            for cw in word:
                for cbl in brokenLetters:
                    if (cw == cbl):
                        flag = True
                        break

                if flag:
                    break
            if not flag:
                count += 1

        return count
    
                

        