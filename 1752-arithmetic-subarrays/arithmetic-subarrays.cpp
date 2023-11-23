class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i = 0 ; i<l.size() ; i++){
            int leftRange = l[i];
            int rightRange = r[i];

            vector<int> query(nums.begin() + leftRange, nums.begin() + rightRange + 1);
            sort(query.begin(), query.end());

            bool flag = true;
            int diff = query[1] - query[0];
            for(int  k = 1 ; k < query.size()-1 ; k++){
               if(query[k+1] - query[k] != diff){
                flag = false;
                break;
               }
            }

        ans.push_back(flag);

        }
        return ans;
    }
};