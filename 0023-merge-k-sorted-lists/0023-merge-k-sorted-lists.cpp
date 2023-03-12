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
    ListNode* create(priority_queue<int>& pq){
        if(pq.empty())return NULL;
        
        ListNode* head=new ListNode(-pq.top());
        pq.pop();
        head->next=create(pq);
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> pq;
        for(auto* temp: lists){
            while(temp!=NULL){
                pq.push(-temp->val);
                temp=temp->next;
            }
        }
        
        return create(pq);
    }
};