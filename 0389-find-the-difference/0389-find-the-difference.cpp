class Solution {
public:
    char findTheDifference(string s, string t) {
        int c = 0,c1 =0;
        char c3;
        for(int i = 0 ;i<s.size(); i++){
            c += s[i];
        }
        for(int i = 0 ; i<t.size() ; i++){
           c1 += t[i];
        }
        if(c != c1 ){
            c3 = (char)(c1-c);
        }

        return c3;
    }
};