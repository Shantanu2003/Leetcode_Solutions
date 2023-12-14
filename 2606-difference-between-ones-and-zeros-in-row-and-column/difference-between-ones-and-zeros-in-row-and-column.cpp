class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>rowOnes(n,0);
        vector<int>colOnes(m,0);
        vector<int> rowZeros(n, 0);
        vector<int> colZeros(m, 0);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    rowOnes[row]++;
                    colOnes[col]++;
                }
                else{
                    rowZeros[row]++;
                    colZeros[col]++;
                }
            }
        }
        for(int i = 0 ; i  < n ; i++){
            for(int j = 0 ; j < m ; j++){
                grid[i][j] = rowOnes[i] + colOnes[j] - rowZeros[i] - colZeros[j]; 
            }
        }
     return grid;
    }
};