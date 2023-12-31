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
class BSTIterator {
public:
    stack<TreeNode*> nodes;

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* top = nodes.top();
        nodes.pop();
        pushAllLeft(top->right);
        return top->val;
    }

    bool hasNext() {
        return !nodes.empty();
    }

private:
    void pushAllLeft(TreeNode* root) {
        while (root) {
            nodes.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */