class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;  // Check for an empty matrix
        int col = matrix[0].size();
        int maxArea = 0;
        std::vector<int> heights(col, 0);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                // Update the height if the current element is '1', else reset it to 0
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            // Calculate the maximum area for the current row
            std::stack<int> stack;
            for (int j = 0; j <= col; ++j) {
                while (!stack.empty() && (j == col || heights[j] < heights[stack.top()])) {
                    int height = heights[stack.top()];
                    stack.pop();
                    int width = stack.empty() ? j : j - stack.top() - 1;
                    maxArea = std::max(maxArea, height * width);
                }
                stack.push(j);
            }
        }

        return maxArea;
    }
};