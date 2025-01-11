class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mp;
        for(char c: s){
           mp[c]++;
        }
        int count = 0;
        for(auto i : mp){
            if(i.second % 2 != 0)
            count++;
        }
        if(count > k || s.size() < k)
        return false;
        else
        return true;
    }
};