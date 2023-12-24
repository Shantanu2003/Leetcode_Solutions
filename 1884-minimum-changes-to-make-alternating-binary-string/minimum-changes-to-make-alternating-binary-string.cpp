class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] != s[i-1])
            continue;

            else{
                if(s[i] == '0'){
                s[i] = '1';
                count++;
            }
                else{
                s[i] ='0';
                count++;
            }
            }
        }
        return min(count, static_cast<int>(s.size()) - count);
    }
};