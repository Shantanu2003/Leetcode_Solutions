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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        
        int countA = 0;
        ListNode* addressA = NULL;
        while(temp && countA != a){
            countA++;
            addressA = temp;
            temp = temp->next;
        }
        if (addressA != NULL) {
        addressA->next = list2;
        }

        int countB = 0;
        ListNode* addressB = NULL;
        while(temp &&  countB != b - a +1){
            countB++;
            addressB = temp->next;
            temp = temp->next;
        }

        ListNode* addressLastNodeOfList2 = list2;
        while(addressLastNodeOfList2->next != NULL){
            addressLastNodeOfList2 = addressLastNodeOfList2->next;
        }

        addressLastNodeOfList2->next = addressB;

        return list1;

    }
};