class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<int>ans;
        for(auto i : mp){
            if(ans.size() == 2)
            break;
            if(i.second == 1)
            ans.push_back(i.first);
        }
        return ans;
    }
};