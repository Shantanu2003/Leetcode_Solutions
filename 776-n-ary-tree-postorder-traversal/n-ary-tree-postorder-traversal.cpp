/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     void dfs(Node* root, vector<int>& ans) {
        if(root == NULL)
            return;

        // Traverse all children first
        for(Node* child : root->children) {
            dfs(child, ans);
        }
        
        // Then add the current node's value
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

};