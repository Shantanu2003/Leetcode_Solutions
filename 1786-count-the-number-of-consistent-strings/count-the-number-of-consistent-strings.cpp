class Solution {
public:
    bool helper(set<char>s, string str){
    for(char c: str){
           if(s.find(c) == s.end())
           return false;
       }
       return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
          set<char>s;
          for(char c: allowed)
          s.insert(c);

          int count = 0;
          for(string str: words){
            if(helper(s,str))
            count++;
          }
    return count;
    }
};