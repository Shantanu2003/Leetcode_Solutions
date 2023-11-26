class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 1)
                    matrix[i][j] = matrix[i-1][j] + 1;
                else if(matrix[i][j] == 0)
                    matrix[i][j] = 0; // assuming default value for 0
            }
        }

        // Sort each row in non-increasing order
        for(int i = 0; i < row; i++){
            sort(matrix[i].rbegin(), matrix[i].rend());
        }

        // Calculate the largest submatrix
        int maxArea = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int height = matrix[i][j];
                int width = j + 1; // cumulative count of ones
                maxArea = max(maxArea, height * width);
            }
        }

        return maxArea;
    }
};