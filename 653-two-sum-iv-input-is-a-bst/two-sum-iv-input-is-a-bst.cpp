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
    bool traverseAndCheck(TreeNode* root, int k, unordered_set<int>& mp) {
        if (root == nullptr) {
            return false;
        }

        int complement = k - root->val;
        if (mp.count(complement)) {
            return true;
        }

        mp.insert(root->val);

        return traverseAndCheck(root->left, k, mp) || traverseAndCheck(root->right, k, mp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>mp;
        return traverseAndCheck(root,k,mp);
    }
};