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
bool helper(TreeNode* leftSubtree, TreeNode* rightSubtree) {
            // If both subtrees are empty, they are symmetric
            if (!leftSubtree && !rightSubtree) {
                return true;
            }
            // If one of the subtrees is empty, they are not symmetric
            if (!leftSubtree || !rightSubtree) {
                return false;
            }
            // Check if the values of the nodes match and their subtrees are symmetric
            return (leftSubtree->val == rightSubtree->val) &&
                   helper(leftSubtree->left, rightSubtree->right) &&
                   helper(leftSubtree->right, rightSubtree->left);
        }
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL){
            return true;
        }
        return helper(root->left,root->right);
    }
};