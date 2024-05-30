class Solution {
public:
  void findArray(vector<int>& ans) {


        for(int  i = 1; i<ans.size() ; i++){
            ans[i] = ans[i-1]^ans[i];
        }
    }
    int countTriplets(vector<int>& arr) {
        vector<int>ans(arr.begin(), arr.end());
        ans.insert(ans.begin(), 0);

        findArray(ans);
        int res = 0;
        for(int  i = 0 ; i < ans.size() ; i++){
            for(int j = i+1 ; j < ans.size() ; j++){
                if(ans[i] == ans[j])
                res += (j-i)-1;
            }
        }
    return res;
    }
};