class Solution {
public:
    int getLucky(string s, int k) {
        string res = "";
        for(char c: s){
            res += to_string(c - 'a' + 1);
        }

        string ans = res;
        while(k > 0){
            long long sum = 0;

            for(char c: ans){
                sum += c- '0';
            }
            ans = to_string(sum);
            k--;
        }

        return stoi(ans);
    }
};