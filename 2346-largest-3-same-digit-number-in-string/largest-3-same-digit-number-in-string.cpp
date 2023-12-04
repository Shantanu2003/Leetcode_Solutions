class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_set<string> s = {"000","111","222","333","444","555","666","777","888","999"};
        string ans = "";
        for(int  i = 0 ; i < num.size()-2 ; i++){
           string res = num.substr(i,3);
           if(s.find(res) != s.end() && res > ans){
               ans = res;
           }
        }
        return ans;
    }
};