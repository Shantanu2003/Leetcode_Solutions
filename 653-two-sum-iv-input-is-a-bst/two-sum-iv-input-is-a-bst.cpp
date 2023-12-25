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
    vector<int> inorder(TreeNode* root, vector<int> &ans){
        if(root ==NULL){
            return {};
        }
        
        ans.push_back(root->val);
        inorder(root->left, ans);
        inorder(root->right,ans);

        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>mp;
        vector<int> ans;
        inorder(root,ans);
        int n = ans.size();

        for (int i = 0; i < n; i++) {
            int complement = k - ans[i];
            if (mp.count(complement)) {
                return true;
            }
            mp.insert(ans[i]);
        }
    return false;
    }
};