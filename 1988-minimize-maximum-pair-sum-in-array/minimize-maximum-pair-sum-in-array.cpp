class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());

       int high = nums.size() -1;
       int  low = 0; 
       int maxi = INT_MIN;

       while(low<=high){
           int sum = 0;
           sum = nums[low]+ nums[high];
           maxi = max(maxi,sum);
           low++;
           high--;
       }

       return maxi;
    }
};