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
void dfs(TreeNode* root, vector<string>&res, string ans){
    if(root == NULL){
        return;
    }
    if(!root->left && !root->right){
        ans += ('a' + root->val);
        reverse(ans.begin(), ans.end());
        res.push_back(ans);
    }

    ans += ('a' + root->val);

    dfs(root->left, res,ans);
    dfs(root->right, res,ans);   
}
    string smallestFromLeaf(TreeNode* root) {
        vector<string>res;
        dfs(root,res, "");

        sort(res.begin(), res.end());

        return res[0];
    }
};