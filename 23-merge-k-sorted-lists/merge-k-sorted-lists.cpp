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
        for(int i = 0 ; i<lists.size(); i++){
            ListNode* head= lists[i];
            while(head){
                ans.push_back(head->val);
                head = head->next;
            }
            lists[i] = nullptr;
        }
        if(ans.empty()){
            return nullptr;
        }
        sort(ans.begin(),ans.end());
        ListNode* newNode = new ListNode(ans[0]);
        ListNode* current = newNode;

        for (int i = 1; i < ans.size(); i++) {
            current->next = new ListNode(ans[i]);
            current = current->next;
        }

        return newNode;
    }
};