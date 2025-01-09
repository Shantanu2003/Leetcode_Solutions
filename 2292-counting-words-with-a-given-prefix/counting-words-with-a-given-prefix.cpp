class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        int count = 0;
        for(int i = 0 ;i < words.size() ; i++){
            string s = words[i].substr(0,len);
            if (s == pref)
            count++;
        }
        return count;
    }
};