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
string preorder(TreeNode* root){ 
    string ans;
    if(root == NULL){
        return "";
    }

    
    ans += to_string(root->val);

    string leftStr = preorder(root->left);
    string rightStr = preorder(root->right);

    if (!leftStr.empty() || !rightStr.empty()) {
        ans += "(" + leftStr + ")";
    }

    if (!rightStr.empty()) {
        ans += "(" + rightStr + ")";
    }
    return ans;
}
    string tree2str(TreeNode* root) {
        string ans = "";
        ans = preorder(root);
        return ans;
    }
};