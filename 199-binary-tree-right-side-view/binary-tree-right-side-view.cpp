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
public:
    vector<int> helper(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL){
            return ans;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }
       
       helper(root->right, ans, level+1);
       helper(root->left, ans,level+1);

       return ans;
     }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;

        ans = helper(root,ans, 0);
        return ans;
    }
};