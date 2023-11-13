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
    void helper(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& q) {
        if (root == nullptr) {
            return;
        }
        q.push(root->val);
        helper(root->left, q);
        helper(root->right, q);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> q;

        helper(root, q);

        while (k - 1 > 0) {
            q.pop();
            k--;
        }
        return q.top();
    }
};