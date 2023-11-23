class Solution {
public:
    void help(int i,  string s, set<string>&wordDict,vector<string>&ans,string currentCombination){
        if(i==s.size()){   
            ans.push_back(currentCombination);
            return;
        }
        string temp;
        for(int  j = i; j < s.size() ; j++){
            temp +=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                string newCombination = (currentCombination.empty()) ? temp : currentCombination + " " + temp;
                help(j+1,s,wordDict,ans,newCombination);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<string>ans;
        for(auto it:wordDict) st.insert(it);
        help(0,s,st,ans,"");     
        return ans;
    }     
};