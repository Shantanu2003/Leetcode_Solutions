class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int expectedSum= n*(n+1)/2;
        int realSum =0;
        realSum = accumulate(nums.begin(), nums.end(), realSum);
        for(int i = 0; i < nums.size()-1 ; i++){
             if(nums[i] == nums[i+1]){
                 ans[0] = nums[i];
                 ans[1] = expectedSum -(realSum - nums[i]); 
                 break;
             }
        }
        return ans;
    }
};