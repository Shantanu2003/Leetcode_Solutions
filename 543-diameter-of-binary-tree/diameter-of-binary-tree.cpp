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
    int  dfs(TreeNode* root,int& count){
        if(root == NULL)
        return  0;

       int left = dfs(root->left, count);
       int right = dfs(root->right,count);

       count = max(count, left + right);
 
       return 1 + max(left, right);


    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
        return  0;

        int count1 = 0;
        
        dfs(root, count1);

        
        return count1;
    }
};