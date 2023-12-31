class Solution(object):
    def __init__(self):
        # Dictionary to store previously calculated Fibonacci values
        self.memo = {}

    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n in self.memo:
            return self.memo[n]

        if n == 0:
            result = 0
        elif n == 1 or n == 2:
            result = 1
        else:
            result = self.fib(n - 1) + self.fib(n - 2)

        # Memoize the result
        self.memo[n] = result
        return result




