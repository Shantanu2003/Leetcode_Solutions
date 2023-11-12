/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root== p || root == q){
        return root;
    }

    TreeNode* left = helper(root->left, p,q);
    TreeNode* right = helper(root->right, p, q);

    if(left != NULL && right!= NULL){
        return root;
    }
    else if(!left){
        return right;
    }
    else{
        return left;
    }
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return helper(root,p,q);
        
    }
};