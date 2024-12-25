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
    vector<int> largestValues(TreeNode* root) {
    vector<int> result;
     
    if (!root) return result;

    if (root == nullptr) {
            return vector<int>{};
        }

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();
        int curr_max = INT_MIN;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            curr_max = max(curr_max, node->val);

            if (node->left) {
                nodeQueue.push(node->left);
            }
            if (node->right) {
                nodeQueue.push(node->right);
            }
        }

        result.push_back(curr_max);
    }
    return result;
    }
};