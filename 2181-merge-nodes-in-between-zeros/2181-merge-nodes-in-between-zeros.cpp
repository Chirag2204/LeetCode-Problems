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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head->next;
       while(temp1!=NULL){
           if(temp1->val==0){
               temp->next=temp1->next?temp1->next:NULL;
               temp=temp->next;
               temp1=temp1->next;
           }else{
               
               temp->val+=temp1->val;
           }
           if(temp1)
           temp1=temp1->next;
           
       }
        
    
        return head;
    }
};