class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Start from the second-to-last row and move upwards
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < n; ++col) {
                int down = matrix[row + 1][col]; // Move straight down

                int left = (col > 0) ? matrix[row + 1][col - 1] : INT_MAX; // Move down-left
                int right = (col < n - 1) ? matrix[row + 1][col + 1] : INT_MAX; // Move down-right

                // Update the current cell with the minimum falling path sum
                matrix[row][col] += min(down, min(left, right));
            }
        }

        // The answer will be the minimum value in the first row
        int minPathSum = INT_MAX;
        for (int col = 0; col < n; ++col) {
            minPathSum = min(minPathSum, matrix[0][col]);
        }

        return minPathSum;
    }
};
