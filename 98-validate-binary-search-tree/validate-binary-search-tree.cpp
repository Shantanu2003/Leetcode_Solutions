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
bool isValidBST(TreeNode* root) {
        // Call the helper function with initial range constraints
        return helper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool helper(TreeNode* root, long long lower, long long upper) {
        // Base case: an empty tree is a valid BST
        if (root == nullptr) {
            return true;
        }

        // Check the current node's value against the range constraints
        if (root->val <= lower || root->val >= upper) {
            return false;
        }

        // Recursively check the left and right subtrees with updated constraints
        return helper(root->left, lower, root->val) &&
               helper(root->right, root->val, upper);
    }
};