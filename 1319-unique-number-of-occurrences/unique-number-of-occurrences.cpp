class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>mp1;


        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }

        for(const auto& i:mp){
            if(mp1.find(i.second) != mp1.end()){
                return false;
            }
            mp1.insert(i.second);
        }
        return true;
    }
};