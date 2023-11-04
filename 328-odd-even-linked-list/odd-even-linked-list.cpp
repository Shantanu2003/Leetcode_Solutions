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
    ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) {
            return head; // No need to rearrange if the list has 0 or 1 nodes.
        }

    ListNode* fast = head;
    ListNode* slow = head->next;
    ListNode* temp = fast;
    ListNode* prev = slow;

    while(prev && prev->next){
       temp->next = prev->next; 
       temp = temp->next;
       prev->next = temp->next;
       prev = prev->next;
    }

    temp->next = slow;
    return head;
    }
};