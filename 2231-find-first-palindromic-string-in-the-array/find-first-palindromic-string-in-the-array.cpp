class Solution {
public:
    string reverse(string s){
        string res = "";
        for(int i = s.size() - 1 ; i >= 0 ; i-- ){
            res += s[i]; 
        }
        return res;
    }
    string firstPalindrome(vector<string>& words) {
        for(string s: words){
          string rev = reverse(s);

          if(s == rev)
          return s;
        }
    return "";
    }
};