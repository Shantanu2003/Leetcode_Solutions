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
    int maxDepth(TreeNode* root) {
        int ans;

        if(root == NULL){
        ans= 0;
        }
    
        else{
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        ans= max(left,right)+1;
        
        }
        return ans;
    }
};