class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        numeral_map = {
        1000: 'M', 900: 'CM', 500: 'D', 400: 'CD',
        100: 'C', 90: 'XC', 50: 'L', 40: 'XL',
        10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'
        }

        result = ""
        
        #Dictionary is sorted in descending order of values using reverse
        for value, symbol in sorted(numeral_map.items(), reverse=True):
            while num >= value:
                result += symbol
                num -= value

        return result