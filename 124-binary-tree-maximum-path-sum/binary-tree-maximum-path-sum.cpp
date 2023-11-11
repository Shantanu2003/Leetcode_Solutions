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
    int dfs(TreeNode* root, int &maxVal ){
        if(root == NULL){
            return 0;
        }
        
        int left= dfs(root->left,maxVal);
        int right= dfs(root->right,maxVal);

        int res= max(max(left,right)+ root->val, root->val);


        maxVal = max(maxVal,max(res, root->val + left+right));

        
        return res;

    }
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }
};