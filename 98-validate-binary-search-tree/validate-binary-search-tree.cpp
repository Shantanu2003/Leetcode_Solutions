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
private:
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        // Check the left subtree
        if (!isValidBST(root->left)) {
            return false;
        }

        // Check the current node's value
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }

        // Update the previous node to the current node
        prev = root;

        // Check the right subtree
        return isValidBST(root->right);
    }

};