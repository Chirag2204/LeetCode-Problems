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
    ListNode* deleteMiddle(ListNode* head) {
       ListNode* slow=head;
        ListNode* fast=head;
        ListNode* ans=slow;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==head)return NULL;
        while(ans->next and ans->next!=slow)ans=ans->next;
        if(ans->next)
        ans->next=ans->next->next;
        return head;
    }
};