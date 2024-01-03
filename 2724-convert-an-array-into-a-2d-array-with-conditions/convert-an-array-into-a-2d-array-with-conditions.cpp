class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,int> rowFrequency;

        for(int i= 0; i < nums.size() ; i++){
          if(rowFrequency[nums[i]] >= ans.size()){
              ans.push_back({});
          }
           ans[rowFrequency[nums[i]]].push_back(nums[i]);
           rowFrequency[nums[i]]++;
        }
        return ans;
    }
};