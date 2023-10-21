class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int res = nums[0];
        for(int  i = 1 ; i  <nums.size(); i++){
            while(i-heap.top().second>k){
                heap.pop();
            }
           

            int curr = max(0,heap.top().first) + nums[i];
            res = max(res,curr);
            heap.push({curr,i});

        }
        return res;
    }
};