class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        // Start from the second row and update the matrix to store the minimum falling path sum
        for (int row = 1; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int minPrev = matrix[row - 1][col];
                if (col > 0) { //diagonally left
                    minPrev = min(minPrev, matrix[row - 1][col - 1]);
                }
                if (col < n - 1) { //diagonally right
                    minPrev = min(minPrev, matrix[row - 1][col + 1]);
                }
                matrix[row][col] += minPrev;
            }
        }

        // Find the minimum sum in the last row
        return *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
    }
};