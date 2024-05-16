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
 bool dfs(TreeNode* root){
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    bool leftTree = dfs(root->left);
    bool rightTree = dfs(root->right);

    bool res;

    if(root->val == 2){
        res = leftTree | rightTree;
    }
    else{
        res = leftTree & rightTree;
    }
    return res;
 }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};