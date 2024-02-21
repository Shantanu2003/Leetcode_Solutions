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
void numberLine(TreeNode* root,  map<int, map<int, vector<int>>>& mp){
    queue<pair<pair<int, int>, TreeNode*>> q;

    if(root == NULL)
    return;

    q.push({{0,0},root});

    while(!q.empty()){
        auto curr = q.front();
        int level = curr.first.first;
        int depth = curr.first.second;
        TreeNode* node = curr.second;
        mp[level][depth].push_back(node->val);


        q.pop();

        if(node->left != NULL){
            q.push({{level-1,depth+1}, node->left});

        }

        if(node->right != NULL){
            q.push({{level+1,depth+1}, node->right});
        }
    }
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        numberLine(root,mp);
        vector<vector<int>> ans;

        for (auto& i : mp) {
            vector<int>res;
            for(auto j: i.second){
            auto& nodes = j.second;
            sort(nodes.begin(), nodes.end());
            res.insert(res.end(), nodes.begin(), nodes.end());
        }
        ans.push_back(res);
    }
        return ans;
    }
};