class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int operations = 0;
        for(int i =  nums.size()-1; i > 0 ; i--){
             if (nums[i - 1] == nums[i]) {
                continue;
            } else {
                operations += nums.size() - i;
            }
        }
        return operations;
    }
};