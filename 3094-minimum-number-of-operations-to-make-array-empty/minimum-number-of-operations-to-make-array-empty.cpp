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
            else if(i.second % 3 == 0){
                count += i.second/3;
            }
            else{
                count += std::min((i.second / 2), static_cast<int>(std::ceil(i.second / 3.0)));
            }
        }
        return count;
    }
};