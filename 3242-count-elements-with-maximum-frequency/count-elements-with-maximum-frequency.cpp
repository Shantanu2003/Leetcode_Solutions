class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num: nums){
           mp[num]++;
        }
        int maxFreq = INT_MIN;

        for(auto i : mp)
        maxFreq = max(maxFreq,i.second);

        int count = 0;
        for(auto i: mp){
            if(i.second == maxFreq){
                count++;
            }
        }
        return maxFreq*count;
    }
};