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
    priority_queue<int, vector<int>, greater<int>> q;

    void traverse(TreeNode* root) {
        if (root) {
            traverse(root->left);
            q.push(root->val);
            traverse(root->right);
        }
    }

    BSTIterator(TreeNode* root) {
        traverse(root);
    }

    int next() {
        int top1 = q.top();
        q.pop();
        return top1;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */