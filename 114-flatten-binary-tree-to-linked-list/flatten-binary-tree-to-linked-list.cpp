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
    TreeNode* prev = NULL;
     void flatten(TreeNode* root){
        if(!root) return;
        prev = root;
        flatten(root->left);
        TreeNode* temp = prev; 
        flatten(root->right);
        if(root->left){
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};