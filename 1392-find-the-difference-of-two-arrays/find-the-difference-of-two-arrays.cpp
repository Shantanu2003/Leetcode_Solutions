class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        vector<vector<int>> ans;
        vector<int> res;
        
        for(int  i = 0 ; i < nums1.size() ; i++){
            mp1[nums1[i]]++;
        }

        for(int  i = 0 ;  i< nums2.size() ; i++){
            mp2[nums2[i]]++;
        }

        for(const auto& i: mp1){
           if(mp2.find(i.first) == mp2.end())
           res.push_back(i.first);
        }
        ans.push_back({res});

        res.clear();
        
        for(const auto& i: mp2){
           if(mp1.find(i.first) == mp1.end())
           res.push_back(i.first);
        }
        ans.push_back({res});

        return ans;

    }
};