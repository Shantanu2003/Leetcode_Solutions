class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int ans = 0;
        for(int  i =0; i < n; i++){
            if(i % 7 != 0){
              res += ans+1;
              ans++;
            }
            else{
                ans = i/7 + 1;
                res += ans;
            }
        }
        return res;
    }
};