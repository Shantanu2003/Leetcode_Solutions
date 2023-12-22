class Solution {
public:
    int maxScore(string s) {
        int sum = 0, maxSum = -1;
        for(int  i = 0 ; i < s.size() ; i++){
            sum += (s[i] -'0');
        }
        for(int  i = 0 ;i < s.size()-1 ; i++){
            if( s[i] == '0'){
                sum += 1;
            }
            else{
                sum -= 1;
            }
            maxSum = max(maxSum, sum);
        }
    return maxSum;
    }
};