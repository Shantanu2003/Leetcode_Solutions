class Solution {
public:
    void solve(vector<int>nums, set<vector<int>>&ans, int index){
        if(index==nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j = index ; j < nums.size(); j++){
            if(j>index && nums[j] == nums[index])continue;
            swap(nums[index], nums[j]);
            solve(nums,ans,index+1);
            swap(nums[index], nums[j]);
        }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() ,nums.end());
        set<vector<int>> ans;
        vector<vector<int>> vec;
        int index = 0;
        solve(nums,ans, index);
        for(auto it:ans){
            vec.emplace_back(it);
        }
        return vec;
    }
};