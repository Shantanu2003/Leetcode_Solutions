class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int  i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int count = 0;
        for(auto i: mp){
            if(i.second == 1){
                return -1;
            }
            count += min((i.second / 2), static_cast<int>(ceil(i.second / 3.0)));
        }
        return count;
    }
};