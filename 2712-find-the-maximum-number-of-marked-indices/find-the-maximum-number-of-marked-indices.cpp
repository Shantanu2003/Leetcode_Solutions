class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = ((nums.size() +1)/2);
        int count = 0;
        while(high < nums.size()){
            if(2*nums[low] <= nums[high]){
                count +=2;
                high++;
                low++;
            }
            else{
                high++;
            }
        }
    return count;
    }
};