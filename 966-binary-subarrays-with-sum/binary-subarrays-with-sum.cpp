class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int n = nums.size();
        vector<long long> res(n + 1, 0);
        int count = 0;
        unordered_map<long long, int> mp;
        long long cumulativeSum = 0;

        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];
            if (cumulativeSum == goal) {
                count++;
            }
            if (mp.find(cumulativeSum - goal) != mp.end()) {
                count += mp[cumulativeSum - goal];
            }
            mp[cumulativeSum]++;
        }

        return count;
    }
};