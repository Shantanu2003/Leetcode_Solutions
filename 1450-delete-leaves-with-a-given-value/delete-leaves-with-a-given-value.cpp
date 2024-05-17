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
    TreeNode* dfs(TreeNode* root, int x){
        if(root == NULL){
            return NULL;
        }


        root->left = dfs(root->left,x);
        root->right = dfs(root->right,x);

        if(root->left == NULL && root->right == NULL && root->val == x){
              return NULL;
        }

        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL)
        return NULL;
        
        return dfs(root,target);
    }
};