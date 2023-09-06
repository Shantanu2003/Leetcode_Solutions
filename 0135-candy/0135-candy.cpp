class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum ;
        vector<int> ans(n,1);

        for(int i=1 ; i<n; i++){
           if(ratings[i]>ratings[i-1]){
               ans[i]= ans[i-1]+1;
           }
        }
        sum = ans[n-1];
        for(int i = n-2; i>=0 ; i--){
            if(ratings[i]>ratings[i+1]){
                ans[i] = max(ans[i], ans[i+1]+1);
            }
            sum += ans[i];
        }
        return sum;
    }
};

