class Solution {
public:
    int tribonacci(int n) {
        vector<int> ans(38,0);
        ans[0] = 0;
        ans[1] = ans[2] = 1;
        for(int j = 3 ; j <= n ; j++){
            ans[j] = ans[j-1] + ans[j-2] + ans[j-3]; 
        }
    return ans[n];

    }
};