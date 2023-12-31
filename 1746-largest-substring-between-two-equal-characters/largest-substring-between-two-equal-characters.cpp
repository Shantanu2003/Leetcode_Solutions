class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int count = -1;
        unordered_map<char,vector<int>>mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]].push_back(i);
        }
        for(auto pairs:mp){
            int maxElement = 0, minimum =0;
            if(pairs.second.size() > 1){
                maxElement = pairs.second[pairs.second.size() - 1]; 
                minimum = pairs.second[0]; 
                count = max(count, maxElement-minimum-1);
            }
        }
    return count;
    }
};