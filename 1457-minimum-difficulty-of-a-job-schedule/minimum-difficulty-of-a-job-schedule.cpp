class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (d > n)
            return -1;

        int result = INT_MAX;
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(d + 1, INT_MAX));

        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= d; ++k) {
                int maxDifficulty = 0;

                for (int j = i - 1; j >= k - 1; --j) {
                    maxDifficulty = std::max(maxDifficulty, jobDifficulty[j]);
                    dp[i][k] = std::min(dp[i][k], (dp[j][k - 1] != INT_MAX) ? (dp[j][k - 1] + maxDifficulty) : INT_MAX);
                }
            }
        }

        result = dp[n][d];

        return (result == INT_MAX) ? -1 : result;
    }
};