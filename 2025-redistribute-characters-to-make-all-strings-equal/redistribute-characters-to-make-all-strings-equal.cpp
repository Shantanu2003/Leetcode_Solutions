class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() == 1)
        return true; 

        int totalCharCount = 0;
        for (const string& s : words) {
            totalCharCount += s.length();
        }

        if (totalCharCount % words.size() != 0) {
            return false;
        }
        vector<int>ans(26,0);

        for(string word: words){
            for(char c :word){
                ans[c-'a']++;;
            }
        }

        for(auto i:ans){
            if(i % words.size() != 0)
            return false;
        }
        return true;
    }
};