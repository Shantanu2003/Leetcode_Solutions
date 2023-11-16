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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int direction = 0;
        if (!root)
        return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Get the number of nodes at the current level
            vector<int>res;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();
  
                res.push_back(current->val);

                    if (current->left)
                        q.push(current->left);

                    if (current->right)
                        q.push(current->right);

            }
            if (direction % 2 != 0) {
                reverse(res.begin(), res.end());
            }
            ans.push_back(res);
            direction++;

        
        }
        return ans;
    }
};