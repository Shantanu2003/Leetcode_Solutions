class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxSize = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            sum = sum + (nums[i] == 1 ? 1 : -1);

            
            if (sum == 0) {
                maxSize = std::max(maxSize, i + 1);
            } else if (mp.find(sum) != mp.end()) {
                maxSize = std::max(maxSize, i - mp[sum]);
            } else {
                mp[sum] = i;
            }

        }
        return maxSize;         
    }
};