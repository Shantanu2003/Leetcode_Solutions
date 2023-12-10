class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                std::swap(maxProd, minProd);
            }

            maxProd = std::max(nums[i], maxProd * nums[i]);
            minProd = std::min(nums[i], minProd * nums[i]);

            result = std::max(result, maxProd);
        }

        return result;
    }
};