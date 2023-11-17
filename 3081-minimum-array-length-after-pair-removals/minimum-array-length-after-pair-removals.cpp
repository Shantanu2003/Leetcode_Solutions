class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int low = 0;
        int high = (nums.size() + 1)/2;
        while(high < nums.size()){
            if(nums[low] < nums[high]){
                low++;
                high++;
            }
            else{
                high++;
            }
        }
        return nums.size() - 2*low;
    }
};