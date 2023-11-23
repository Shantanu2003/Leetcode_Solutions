class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i = 0 ; i<l.size() ; i++){
            int leftRange = l[i];
            int rightRange = r[i];

            vector<int>query;
            for(int j = leftRange; j<= rightRange ; j++){
               query.push_back(nums[j]);
            }
            sort(query.begin(), query.end());
            bool flag = true;
            int diff = query[1] - query[0];
            for(int  k = 1 ; k < query.size()-1 ; k++){
               if(query[k+1] - query[k] == diff)
               flag = true;

               else{
                   flag = false;
                   break;
               }
            }

            if(flag == true){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            query.clear();
        }
        return ans;
    }
};