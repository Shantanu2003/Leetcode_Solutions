/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head || !head->next) {
        // The list has 0 or 1 node, so there's no middle node to delete.
        return head;
    }

        ListNode* current = head;
        ListNode* newHead = new ListNode(-1);  // Create a new dummy node
        ListNode* newCurrent = newHead;

        while (current) {
            bool isDuplicate = false;
            while (current->next && current->val == current->next->val) {
                isDuplicate = true;
                current = current->next;
            }
            newCurrent->next = current;
            if (isDuplicate == false) {
                newCurrent = newCurrent->next;
            }
            
            current = current->next;
        }

        newCurrent->next = nullptr;
        return newHead->next;  // Skip the dummy node
    }
};