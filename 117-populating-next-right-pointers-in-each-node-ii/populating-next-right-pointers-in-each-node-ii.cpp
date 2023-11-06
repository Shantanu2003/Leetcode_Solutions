/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
/*Node* helper(Node* root){
    if(root == NULL){
     return NULL;
    }

    Node* newNode= new Node(root);
    Node* temp= newNode;

    
}*/
public:
    Node* connect(Node* root) {
       if (root == nullptr) {
            return nullptr;
        }

        Node* current = root;

        while (current != nullptr) {
            Node* levelStart = current;
            Node* nextLevelStart = nullptr;

            while (current != nullptr) {
                if (current->left) {
                    if (current->right) {
                        current->left->next = current->right;
                    } else {
                        Node* temp = current->next;
                        while (temp != nullptr) {
                            if (temp->left) {
                                current->left->next = temp->left;
                                break;
                            } else if (temp->right) {
                                current->left->next = temp->right;
                                break;
                            }
                            temp = temp->next;
                        }
                    }

                    if (!nextLevelStart) {
                        nextLevelStart = current->left;
                    }
                }

                if (current->right) {
                    Node* temp = current->next;
                    while (temp != nullptr) {
                        if (temp->left) {
                            current->right->next = temp->left;
                            break;
                        } else if (temp->right) {
                            current->right->next = temp->right;
                            break;
                        }
                        temp = temp->next;
                    }

                    if (!nextLevelStart) {
                        nextLevelStart = current->right;
                    }
                }

                current = current->next;
            }

            current = nextLevelStart;
        }

        return root;
    }

};