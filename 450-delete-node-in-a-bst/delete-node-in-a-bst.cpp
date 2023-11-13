class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root) 
            if(key < root->val) root->left = deleteNode(root->left, key);     
            else if(key > root->val) root->right = deleteNode(root->right, key);       
            else{
                if(!root->left && !root->right) return NULL;          
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;   
					                                                  
                TreeNode* temp = root->right;                        
                while(temp->left != NULL) temp = temp->left;     
                root->val = temp->val;                            
                root->right = deleteNode(root->right, temp->val);  
            }
        return root;
    }   
};