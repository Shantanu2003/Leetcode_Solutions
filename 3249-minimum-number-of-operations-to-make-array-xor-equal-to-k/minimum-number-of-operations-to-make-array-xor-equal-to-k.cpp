class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = nums[0]; 
        for(int i = 1 ; i < nums.size() ; i++){
            res ^= nums[i];
        }

        if(res == k)
        return 0;

        int count = 0;
        int diff = res ^ k;
        while(diff > 0){
            count += (diff & 1);
            diff >>= 1;
        }
        return count;

    }
};