class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Create a 2D array to store the lengths of common subseq
        int dp[m + 1][n + 1];

        // Fill the dp table using dynamic programming
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0; // Base case: if both empty, LCS is 0
                
                else if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Otherwise, take the maximum of LCS lengths from previous cells
            }
        }
        // Return LCS length
        return dp[m][n];
    }
};