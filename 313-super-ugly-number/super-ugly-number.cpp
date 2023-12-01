class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        vector<long long> ans(n + 1, 0);
        ans[1] = 1;

        vector<long long> primeHelper(primes.size(), 1);

        for (int i = 2; i <= n; ++i) {
            long long nextUgly = INT_MAX;

            for (int j = 0; j < primes.size(); ++j) {
                nextUgly = min(nextUgly, primes[j] * ans[primeHelper[j]]);
            }

            ans[i] = nextUgly;

            for (int j = 0; j < primes.size(); ++j) {
                if (nextUgly == primes[j] * ans[primeHelper[j]]) {
                    primeHelper[j]++;
                }
            }
        }

        return ans[n];
    }
};
