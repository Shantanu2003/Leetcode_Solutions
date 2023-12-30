class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        if(words.size() == 1)
        return true; 
        for(string word: words){
            for(char c :word){
                mp[c]++;
            }
        }

        for(auto i:mp){
            if(i.second % words.size() != 0)
            return false;
        }
        return true;
    }
};