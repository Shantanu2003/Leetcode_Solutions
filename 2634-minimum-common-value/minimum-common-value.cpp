class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       set<int>s;
       for(int  i : nums1)
       s.insert(i);

       for(int num: nums2){
           if(s.find(num) != s.end())
           return num;
       }
       return -1;
    }
};