#include <iostream>
#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        // Vector to store memoized Tribonacci values
        memo.resize(n + 1, -1);

        return tribonacciMemo(n);
    }

private:
    std::vector<int> memo;

    int tribonacciMemo(int n) {
        // Check if the result for 'n' is already memoized
        if (memo[n] != -1) {
            return memo[n];
        }

        // Base cases
        if (n == 0) {
            return memo[n] = 0;
        } else if (n == 1 || n == 2) {
            return memo[n] = 1;
        }

        // Recursive calculation
        return memo[n] = tribonacciMemo(n - 1) + tribonacciMemo(n - 2) + tribonacciMemo(n - 3);
    }
};
