class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        unordered_set<int>s;

        for(int num : nums){
             s.insert(num);
        }

        for(auto i : s){
            if(s.find(-i) != s.end())
            res = max(res,i);
        }

        return res;
    }
};