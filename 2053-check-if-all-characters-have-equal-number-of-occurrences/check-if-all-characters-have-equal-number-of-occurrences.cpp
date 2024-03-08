class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        for(char c: s)
        mp[c]++;

        int start = mp.begin()->second;

        for(auto i : mp){
            if(i.second != start)
            return false;
        }
        return true;
    }
};