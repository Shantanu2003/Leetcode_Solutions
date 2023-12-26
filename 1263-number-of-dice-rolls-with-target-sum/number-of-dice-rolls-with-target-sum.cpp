class Solution {
public:
const int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));

    // Base case: There is one way to achieve a sum of 0 with 0 dice.
    dp[0][0] = 1;

    // Dynamic programming to calculate the number of ways to get each sum with the given number of dice.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            for (int face = 1; face <= k; ++face) {
                if (j - face >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                }
            }
        }
    }

    return dp[n][target];
    }
};