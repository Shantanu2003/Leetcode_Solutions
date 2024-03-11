class Solution {
public:

    string customSortString(string order, string s) {
      unordered_map<char,int>mp;
      unordered_set<char>s1 ;
      for(char c: s)
      mp[c]++;
      string res = "";
      for(char c: order){
          s1.insert(c);
          if(mp.find(c) != mp.end()){
                res.append(mp[c], c);
          }
      }
      for(auto i : mp){
          if(s1.find(i.first) == s1.end())
                res.append(i.second, i.first);
      }

    return res;

    }
};