class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         vector<vector<int>>res(m, vector<int>(n));
         int n1 = original.size();
         if(m*n != n1)
         return {};
        int j = 0, k = 0;;
         for(int i = 0 ; i < n1 ; i++){
            if(i != 0 && i % n == 0){
                j++;
                k = 0;
            }
            res[j][k++] = original[i];
         }
         return res;
    }
};