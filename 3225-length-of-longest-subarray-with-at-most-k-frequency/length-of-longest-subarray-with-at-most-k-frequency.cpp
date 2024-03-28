class Solution {
public:
int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLength = 0;
        int start = 0;
        unordered_map<int, int> freqMap;

        for (int end = 0; end < nums.size(); end++) {
            freqMap[nums[end]]++;

            while (freqMap[nums[end]]> k) {
                freqMap[nums[start]]--;
                if (freqMap[nums[start]] == 0)
                    freqMap.erase(nums[start]);
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};