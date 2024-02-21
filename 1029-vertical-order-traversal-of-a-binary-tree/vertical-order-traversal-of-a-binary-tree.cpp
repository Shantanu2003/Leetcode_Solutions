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
 vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> levels; // Map of vertical levels -> Map of depth -> Nodes
        queue<pair<TreeNode*, pair<int, int>>> q; // Node, {vertical level, depth}

        if (root == nullptr)
            return {};

        q.push({root, {0, 0}}); // Push root with vertical level 0 and depth 0

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto current = q.front();
                q.pop();
                TreeNode* node = current.first;
                int level = current.second.first;
                int depth = current.second.second;

                levels[level][depth].push_back(node->val);

                if (node->left != nullptr)
                    q.push({node->left, {level - 1, depth + 1}});

                if (node->right != nullptr)
                    q.push({node->right, {level + 1, depth + 1}});
            }
        }

        vector<vector<int>> result;
        for (auto& level : levels) {
            vector<int> column;
            for (auto& depth : level.second) {
                vector<int>& nodes = depth.second;
                sort(nodes.begin(), nodes.end());
                column.insert(column.end(), nodes.begin(), nodes.end());
            }
            result.push_back(column);
        }

        return result;
    }

};