class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>freq(nums.size()+1);
        vector<int>res;
        for(int  i = 0 ; i < nums.size() ; i++){
            if(freq[nums[i]] < 0){
              res.push_back(nums[i]);
            }
            else
            freq[nums[i]] = -nums[i];
        }
    return res;
    }
};