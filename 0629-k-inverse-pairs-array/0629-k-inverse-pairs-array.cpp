class Solution {
public:
    int MOD = 1000000007;

    int kInversePairs(int n, int k) {
        
        // 1D vector 'dp' with size 'k + 1' with first element set to 1 and rest set to 0 
        vector<int> dp(k + 1, 0); 
        dp[0] = 1; 

        // Loop through each value of n from 1 to 'n'
        for (int i = 1; i <= n; i++) {
            
            //temp vector to store the next row values, first element to 1
            vector<int> next_dp(k + 1, 0); 
            next_dp[0] = 1;

            // Loop through each value of k from 1 to 'k'
            for (int j = 1; j <= k; j++) {
                // Calculate the current value of next_dp[j] 
                // using the previous row values dp[0] to dp[j]
                next_dp[j] = (next_dp[j - 1] + dp[j]) % MOD;
                
                // Subtract the value of dp[j - i] if j is greater than or equal to i
                // Adding MOD here ensures results are non-negative, MOD again for results within range
                if (j >= i) {
                    next_dp[j] = (next_dp[j] - dp[j - i] + MOD) % MOD; 
                }
            }
            // Update dp with values of 'next_dp' for the next iteration
            dp = next_dp; 
        }

        // Return the value of dp[k], which represents the number of arrays that can form k inverse pairs for given n
        return dp[k];
    }
};