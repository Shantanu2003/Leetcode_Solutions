class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans(grid.size() - 2, vector<int>(grid.size() - 2));
        for(int  i = 0 ; i < grid.size() - 2 ; i++){
             for(int  j = 0; j < grid .size() - 2 ; j++){
                 int maxElement = INT_MIN;
                 for(int l = i; l < i+3 ; l++){
                    for(int k = j; k < j+3 ; k++){
                        maxElement = max(maxElement, grid[l][k]);
                    }
                    ans[i][j] = maxElement;
                 }
             }
        }
        return ans;
    }
};