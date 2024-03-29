class Solution {
public: 
    int findMax(vector<int>& nums){
        int maxEle= INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxEle= max(maxEle, nums[i]);
        }
        return maxEle;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int start = 0;
        long long maxEle = findMax(nums);
        long long count = 0;
        long long ans = 0;

        for(int end = 0 ; end < nums.size()  ; end++){
            if(nums[end] == maxEle)
            count++;

           while(count >= k){
            if(nums[start] == maxEle){
                count--;
            }
            start++;
           }
            
           ans += start;
        }
    return ans;
    }
};