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
pair<int, int> helper(TreeNode* root) {
        if (root == NULL)
            return make_pair(INT_MIN, INT_MAX);

        int maxVal = root->val;
        int minVal = root->val;

        pair<int, int> leftResult = helper(root->left);
        pair<int, int> rightResult = helper(root->right);

        maxVal = max(maxVal, max(leftResult.first, rightResult.first));
        minVal = min(minVal, min(leftResult.second, rightResult.second));

        return make_pair(maxVal, minVal);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL)
            return 0;

        pair<int, int> result = helper(root);

        int leftVal = max(abs(root->val - result.first), abs(root->val - result.second));
        int rightVal = max(leftVal, maxAncestorDiff(root->left));
        rightVal = max(rightVal, maxAncestorDiff(root->right));

        return rightVal;
    }
};