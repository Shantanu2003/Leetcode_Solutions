#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells, std::vector<int>& potions, long long success) {
        std::vector<int> pairs;

        // Sort the potions array for binary search
        std::sort(potions.begin(), potions.end());

        int n = potions.size();
        std::vector<int> prefixSum(n + 1, 0);

        // Calculate the prefix sum
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (potions[i] >= success ? 1 : 0);
        }

        for (int i = 0; i < spells.size(); ++i) {
            int spellStrength = spells[i];

            // Use lower_bound to find the first position where potion strength >= success/spellStrength
            int count = n - (std::lower_bound(potions.begin(), potions.end(), (success + spellStrength - 1) / spellStrength) - potions.begin());

            pairs.push_back(count);
        }

        return pairs;
    }
};
