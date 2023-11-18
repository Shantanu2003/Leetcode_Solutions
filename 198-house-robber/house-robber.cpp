class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int>ans(n+1,0);
        ans[1] = nums[0];
        for(int  i = 2 ; i <= nums.size() ; i++){
            ans[i] = max(ans[i-1], ans[i-2] +nums[i-1]); 
        }
        return ans[n];
    }
};