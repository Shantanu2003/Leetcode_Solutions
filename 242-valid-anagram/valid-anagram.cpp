class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;

        if(s.size() != t.size())
        return false;

        for(char c: s){
            mp[c]++;
        }
        for(char c :t){
            mp1[c]++;
        }

        for(auto i :mp){
            if(mp[i.first] != mp1[i.first])
            return false;
        }


        return true;
    }
};