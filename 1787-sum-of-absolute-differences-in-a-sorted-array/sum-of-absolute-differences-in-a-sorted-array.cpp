class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 0);

        int prefixSum = 0;
        int suffixSum = 0;

        // Calculate the total sum and the initial suffix sum
        for (int i = 0; i < n; i++) {
            suffixSum += nums[i];
        }

        // Calculate the result array
        for (int i = 0; i < n; i++) {
            // Update suffix sum and calculate the result for the current element
            suffixSum -= nums[i];
            result[i] = (nums[i] * i - prefixSum) + (suffixSum - nums[i] * (n - i - 1));

            // Update prefix sum
            prefixSum += nums[i];
        }

        return result;
    }
};