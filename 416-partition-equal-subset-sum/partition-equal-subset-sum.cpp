class Solution {
public:
    bool helper(vector<int>& nums, int target, int index, vector<vector<int>>& dp){         
         if(index == 0)
         return nums[index] == target;

         if(dp[index][target] != -1)
         return dp[index][target];

         bool notTaken = helper(nums,target, index-1,dp);
         bool taken = false;
         if(nums[index] <= target)
         taken = helper(nums,target-nums[index], index-1,dp);

         dp[index][target] = taken || notTaken;

         return dp[index][target];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n ; i++){
            sum += nums[i];
        }
        vector<vector<int>>dp(n, vector<int>((sum/2)+1,-1));

        if(sum % 2 != 0)
        return false;

        return helper(nums,sum/2,n-1,dp);
    }
};