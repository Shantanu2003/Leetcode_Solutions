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
int helper(TreeNode* root,int minValue, int maxValue) {
        if (root == NULL) {
            return maxValue - minValue;
        }

        // Update minValue and maxValue based on the current node's value
        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);

        // Recursively explore the left and right subtrees
        int leftDiff = helper(root->left, minValue, maxValue);
        int rightDiff = helper(root->right, minValue, maxValue);

        // Return the maximum difference among left subtree, right subtree, and the current path
        return max(leftDiff, rightDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
      return helper(root, INT_MAX, INT_MIN);

    }
};