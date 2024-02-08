class Solution {
public:
    int numSquares(int n) {
        //initialise dp vector of size n + 1 with elements of "inf" val
        vector<int> dp(n + 1, INT_MAX);
        //first element to 0
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) { //loop sqrt(n) times
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};