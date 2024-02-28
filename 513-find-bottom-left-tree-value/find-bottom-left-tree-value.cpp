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

void bfs(TreeNode* root,  map<int, vector<int>>& mp){
    queue<pair<int,TreeNode*>> q;

    if(root == NULL)
    return;

    q.push({0,root});

    while(!q.empty()){
        auto curr = q.front();
        int level = curr.first;
        TreeNode* node = curr.second;
        mp[level].push_back(node->val);


        q.pop();

        if(node->left != NULL){
            q.push({level+1, node->left});

        }

        if(node->right != NULL){
            q.push({level+1, node->right});
        }
    }
}

    int findBottomLeftValue(TreeNode* root) {
        map<int, vector<int>> mp;
        bfs(root, mp);
        auto last_entry = mp.rbegin();
        return last_entry->second[0];
    }
};