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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        vector<int>ans;
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(int i = 0 ; i<lists.size(); i++){
            ListNode* head= lists[i];
            while(head){
                pq.push(head->val);
                head = head->next;
            }
            lists[i] = nullptr;
        }
        if(pq.empty()){
            return nullptr;
        }
        ListNode* newNode = new ListNode(-1);
        ListNode* current = newNode;

        while(!pq.empty()){
            current->next = new ListNode(pq.top());
            current = current->next;
            pq.pop();
        }

        return newNode->next;
    }
};