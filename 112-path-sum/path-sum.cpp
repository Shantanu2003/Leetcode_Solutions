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
private:
  int sum(TreeNode* root, int currentSum, int targetSum){
      if (root == nullptr) {
            return false;  // If the node is null, the path sum cannot be equal to the target sum
        }

        // Update the current sum with the value of the current node
        currentSum = currentSum + root->val;

        // If the current node is a leaf node, check if the current sum equals the target sum
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum == targetSum;
        }

        // Recursively check for the target sum in left and right subtrees
        bool leftPath = sum(root->left, currentSum, targetSum);
        bool rightPath = sum(root->right, currentSum, targetSum);

        // Return true if either left or right subtree has a path sum equal to the target sum
        return leftPath || rightPath;
        
  }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        return sum(root, 0, targetSum);
    }
};