class Solution {
public:
const int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        std::vector<int> newDp(target + 1, 0);
        for (int j = 1; j <= target; ++j) {
            for (int face = 1; face <= k; ++face) {
                if (j - face >= 0) {
                    newDp[j] = (newDp[j] + dp[j - face]) % MOD;
                }
            }
        }
        dp = newDp;
    }

    return dp[target];        

    }
};