class Solution {
public:
string helper(const string &s) {
string next;
        int count = 1;

        for (int i = 0; i < s.length(); ++i) {
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                ++count;
            } 
            else {
                next += to_string(count) + s[i];
                count = 1;  // Reset count for the next digit
            }
        }

        return next;
}
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans = "1";
        for(int i= 2; i<=n; i++){
            ans = helper(ans);
        }
        return ans;
    }
};