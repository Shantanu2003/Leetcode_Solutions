class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int  n = edges.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++){
             mp[edges[i][0]]++;
            mp[edges[i][1]]++;

            if(mp[edges[i][0]] > 1)
            return edges[i][0];

            else if(mp[edges[i][1]] > 1)
            return edges[i][1];
        }
        return -1;
    }
};