class Solution {
public:
    int numTilings(int n) {
        if(n <= 1)
        return 1;

        vector<long long>dp(n+1,0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for(int  i = 2 ; i < n ; i++){
            dp[i+1] = (2*dp[i]) % 1000000007 + dp[i-2];
        }
        return dp[n] % 1000000007;
    }
};