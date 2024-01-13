class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>forS;
        unordered_map<int,int>forT;
        int res = 0;
        for(int  i = 0 ; i < s.size(); i++){
            forS[s[i]]++;
            forT[t[i]]++;
        }
        for(auto i :forT){
            if(i.second > forS[i.first])
            res += i.second-forS[i.first];
        }

    return res;
    }
};