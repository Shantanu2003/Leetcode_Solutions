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

//#include <bits/stdc++.h>

class Solution {
public:
    vector<int> inorderNodes;
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);

        inorderNodes.push_back(root->val);
        inorderTraversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {

        inorderTraversal(root);

        int min1 = INT_MAX;
        int diff;
        for(int i = 1 ; i < inorderNodes.size(); i++){
            diff = 0; 
            int diff = abs(inorderNodes[i]-inorderNodes[i-1]);
            min1 = min(min1,diff);
            } 
        return min1;
    }
};