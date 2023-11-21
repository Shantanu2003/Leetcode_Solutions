class Solution {
public:
int rev(int n){
    int sum = 0;
    while(n>0){
        int a = n%10;
        sum = sum*10 + a;
        n=n/10;
    }
    return sum;
}
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        long long pairs = 0;
        for(int i = 0; i< nums.size() ;i++){
            long long diff = nums[i] - rev(nums[i]);
            mp[diff]++;
        }
        for(auto &i :mp){
            if(i.second >= 2){
            pairs += i.second*(i.second - 1)/2;
            }
        }
    return pairs%1000000007;
    }
};