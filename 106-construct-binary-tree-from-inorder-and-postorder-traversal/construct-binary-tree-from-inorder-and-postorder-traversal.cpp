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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    std::unordered_map<int, int> inorder_index;
    for (int i = 0; i < inorder.size(); i++) {
        inorder_index[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1;
    return helper(postorder, inorder, inorder_index,postIndex, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder,unordered_map<int, int>& inorder_index, int& Idx, int left, int right) {
    if (Idx<0 || left > right) {
        return NULL;
    }

    // The first element in the postorder traversal is the root of the current subtree
    int rootValue = postorder[Idx];
    TreeNode* root = new TreeNode(rootValue);

    // Find the index of the root value in the inorder traversal
    int inIndex = inorder_index[rootValue];

    // Move to the next element in the postorder traversal
    Idx--;

    // Recursively build the left and right subtrees
    root->right = helper(postorder, inorder, inorder_index, Idx, inIndex + 1, right);
    root->left = helper(postorder, inorder, inorder_index, Idx, left, inIndex - 1);

    return root;
    }
};