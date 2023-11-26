class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        int maxTransactions = 2;
        vector<vector<int>> dp(maxTransactions + 1, vector<int>(n, 0));

        for (int t = 1; t <= maxTransactions; ++t) {
            int maxDiff = -prices[0];
            for (int i = 1; i < n; ++i) {
                dp[t][i] = max(dp[t][i - 1], prices[i] + maxDiff);
                maxDiff = max(maxDiff, dp[t - 1][i] - prices[i]);
            }
        }

        return dp[maxTransactions][n - 1];
    }
};