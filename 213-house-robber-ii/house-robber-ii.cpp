class Solution {
public:
    int robHelper(const vector<int>& nums, int start, int end) {
        int prevMax = 0;
        int currMax = 0;

        for (int i = start; i <= end; ++i) {
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }

        return currMax;
    }
  int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Rob the first house, skip the last one
        int max1 = robHelper(nums, 0, n - 2);

        // Skip the first house, rob the last one
        int max2 = robHelper(nums, 1, n - 1);

        // Return the maximum of the two scenarios
        return max(max1, max2);
    }
};