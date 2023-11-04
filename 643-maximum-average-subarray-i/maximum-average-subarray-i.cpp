class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double average;
      
        double sum = 0.0;
        for(int i = 0; i< k ; i++){
            sum += nums[i];
        }
        int  left = 0;
        double maxSum = sum;
        for(int i = k; i<nums.size() ;i++){
           double sum2 = 0.0;
           sum2 += nums[i] + sum - nums[left];

           maxSum = max(sum2,maxSum);
           sum = sum2;
           left++;
        }
        average = maxSum/k;
        return average;
    }
};