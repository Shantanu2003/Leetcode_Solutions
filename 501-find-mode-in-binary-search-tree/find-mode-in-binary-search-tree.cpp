/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
void inorder(TreeNode *root,vector<int>& result){
    if (root == NULL)
        return;
 
    inorder(root->left, result);

    result.push_back(root->val);

    inorder(root->right, result);
}
public:
    vector<int> findMode(TreeNode* root) {
       vector<int>ans;
       vector<int>arr;

       inorder(root, ans);

       int maxi = 0;
       int res = 0;

       unordered_map<int,int>mp;
       for(int c: ans){
           mp[c]++;
           maxi = max(maxi, mp[c]);
       }

       for(auto count: mp){
       if(count.second == maxi){
            arr.push_back(count.first);
       }
       }
    return arr;
    }
};