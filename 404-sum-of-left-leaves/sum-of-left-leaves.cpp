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
    int sum = 0;

    int helper(TreeNode* root, int isLeft){
        if(root == NULL)
        return 0;

        if(root->left == NULL && root->right == NULL && isLeft == 1)
        sum += root->val;

        helper(root->left, 1);
        helper(root->right, 0);

        return sum;


    }
    int sumOfLeftLeaves(TreeNode* root) {
         return helper(root,0);
    }
};