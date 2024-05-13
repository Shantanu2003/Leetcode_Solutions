class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Ensure all rows start with 1 by flipping if necessary
        for (int i = 0; i < rows; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Ensure each column has more 1s than 0s by flipping if necessary
        for (int j = 0; j < cols; ++j) {
            int countZero = 0;
            for (int i = 0; i < rows; ++i) {
                countZero += (grid[i][j] == 0);
            }
            if (countZero > rows / 2) {
                for (int i = 0; i < rows; ++i) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        // Calculate the total score
        int score = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                score += grid[i][j] * (1 << (cols - j - 1));
            }
        }

        return score;
    }
};
