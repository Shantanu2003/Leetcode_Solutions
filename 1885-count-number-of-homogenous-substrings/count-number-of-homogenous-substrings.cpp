class Solution {
# define MOD 1000000007
public:
    int countHomogenous(string s) {
        long long sum = 0;
        long long count = 1;
        for(int i = 0 ;i < s.size(); i++){
            if(s[i] == s[i+1]){
                count++;
            }
            else{
               sum += count*(count+1)/2;
               count = 1; 
            }
        }
        return sum % MOD;
    }
};