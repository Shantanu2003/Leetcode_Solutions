class Solution {
public:
    vector <int> countBits(int num) {
        vector<int> ans(num+1);
        int x = 0;
        int b = 1;
        while(b<=num){
            while(x<b && x+b <=num){
                ans[x+b] = ans[x] +1;
                ++x;
            }
            x= 0;
            b<<= 1;
        }
        return ans;
    }
};

/* public class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        int x = 0;
        int b = 1;
    
        // [0, b) is calculated
        while (b <= n) {
            // generate [b, 2b) or [b, n) from [0, b)
            while (x < b && x + b <= n) {
                ans[x + b] = ans[x] + 1;
                ++x;
            }                         
            x = 0; // reset x
            b <<= 1; // b = 2b
        }
                  
        return ans;
    }
} */