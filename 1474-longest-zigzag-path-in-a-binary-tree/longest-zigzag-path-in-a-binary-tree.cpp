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
    int maxi= 0;
    void maxZigZag(TreeNode* root,int direction ,int count){
       if(root == nullptr){
           return;
       }
       maxi=max(maxi,count);
       if(direction == 0){
            maxZigZag(root->left,0, 1);
            maxZigZag(root->right,1,count+1);
       }
       else{
            maxZigZag(root->left,0,count+1);
            maxZigZag(root->right,1,1);
       }

    }
    int longestZigZag(TreeNode* root) {
        maxZigZag(root,1,0);
        maxZigZag(root, 0,0);
        return maxi;
    }
};