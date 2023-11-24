class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        // Start from the second-to-last row and update the values
        for (int i = row - 2; i >= 0; --i) {
            int col = triangle[i].size();
            for (int j = 0; j < col; ++j) {
                // Choose the minimum path sum by adding the current value and the minimum of the two adjacent values in the next row
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // The final minimum path sum is the updated value at the top of the triangle
        return triangle[0][0];
    }
};