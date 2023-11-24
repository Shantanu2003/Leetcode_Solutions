class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // Initialize the first row
        for (int j = 1; j < col; ++j) {
            grid[0][j] += grid[0][j - 1];
        }

        // Initialize the first column
        for (int i = 1; i < row; ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        // Fill in the rest of the grid
         for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // The bottom-right cell now contains the minimum path sum
        return grid[row - 1][col - 1];
    }
};