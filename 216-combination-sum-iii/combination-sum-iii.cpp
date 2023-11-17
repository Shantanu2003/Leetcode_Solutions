class Solution {
public:
vector<vector<int>> ans;
void helper(int idx, int k,vector<int>&current,int n, vector < int > & arr)
    {
        if(current.size()==k && n == 0)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i< arr.size();i++)
        {
            if (arr[i] > n) break;
            current.push_back(arr[i]);  //consider the current element i
            helper(i+1,k,current,n - arr[i],arr); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int>ds;
        helper(0,k,ds,n,arr);
        return ans;
    }
};