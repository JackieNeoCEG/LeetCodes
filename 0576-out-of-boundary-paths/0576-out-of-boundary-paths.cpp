class Solution {
public:
    const int MOD = 1000000007;
    //3D dp vector to store startRow startColumn maxMove
    vector<vector<vector<int>>> memo;
    
    int solve(int n, int m, int maxMove, int startRow, int startColumn) {
                
        // Out of bounds condition to return 1 path
        if (startColumn < 0 || startColumn >= n || startRow < 0 || startRow >= m) {
            return 1;
        }
        
        // Base case: maxMove reached
        if (maxMove == 0) {
            return 0;
        }
        // Initialize memoi vector to have dimensions 50 x 50 x 51 with all values of -1
        // This is based off the problem's constraints due to time limits!
        if (memo.empty()) {
            memo.resize(50, vector<vector<int>>(50, vector<int>(51, -1)));
        }


        // Check if result is memoized
        if (memo[startRow][startColumn][maxMove] != -1) {
            return memo[startRow][startColumn][maxMove];
        }

        // Recursion step to exhaust maxMove
        long long up = solve(n, m, maxMove - 1, startRow - 1, startColumn);
        long long down = solve(n, m, maxMove - 1, startRow + 1, startColumn);
        long long left = solve(n, m, maxMove - 1, startRow, startColumn - 1);
        long long right = solve(n, m, maxMove - 1, startRow, startColumn + 1);

        // Calculate the total paths and store in memoization table
        long long totalPaths = (up + down + left + right) % MOD;
        memo[startRow][startColumn][maxMove] = totalPaths;

        return totalPaths;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return solve(n, m, maxMove, startRow, startColumn);
    }
};