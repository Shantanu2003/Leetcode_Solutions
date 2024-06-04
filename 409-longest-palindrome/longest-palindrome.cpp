class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1)
        return 1;

        unordered_map<char,int>mp;

        for(char c: s){
            mp[c]++;
        }

        int res= 0;
        bool odd = false;

        for(auto i : mp){
            if(i.second %2 == 0)
            res += i.second;

            else{
                res += i.second -1;
                odd = true;
            }
        }
        if (odd) return res + 1;

        return res;

    }
};
