class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long res = 0;
        for(int i = happiness.size() - 1 ; i >= 0 ; i--){
           k--;
           long long ans = happiness[i] - (happiness.size()  - i - 1);
           res += max(ans, 0LL);

           if(k == 0)
           break;
        }

        return res;
        
        
    }
};