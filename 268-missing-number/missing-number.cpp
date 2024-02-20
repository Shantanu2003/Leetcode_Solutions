class Solution {
public:
    int missingNumber(vector<int>& nums) {
                int missing = 0;

        // XOR all numbers from 0 to n
        for (int i = 0; i <= nums.size(); i++) {
            missing ^= i;
        }
        
        // XOR all elements in nums
        for (int num : nums) {
            missing ^= num;
        }
        
        return missing;
    }
};