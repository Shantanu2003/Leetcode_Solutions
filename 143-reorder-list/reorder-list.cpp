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
    ListNode* mid(ListNode* root){
        ListNode* slow = root;
        ListNode* fast = root->next;
        while(fast != NULL and fast->next != NULL){
            fast= fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return; // No need to reorder if there are 0, 1, or 2 nodes
        
        ListNode* middle = mid(head);
        ListNode* list1 = head;
        ListNode* list2 = middle->next;
        middle->next = NULL; // Break the list into two parts
        
        list2 = reverse(list2); // Reverse the second half
        
        ListNode* temp;
        while(list2 != NULL) {
            temp = list1->next;
            list1->next = list2;
            list2 = list2->next;
            list1->next->next = temp;
            list1 = temp;
        }


        head = list1;        

    }
};