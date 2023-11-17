class Solution {
public:
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};