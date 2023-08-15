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
    ListNode* partition(ListNode* head, int x) {
        ListNode* listhead=new ListNode(0); 
        ListNode* list2head=new ListNode(0);
        ListNode* list2=list2head;
        ListNode* list1=listhead;
        ListNode* temp=head;
        while(temp){
            ListNode* temp2=new ListNode(temp->val);
            if(temp->val<x){
                list1->next=temp2;
                list1=list1->next;
            }else{
                list2->next=temp2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        list2head=list2head->next;
        list1->next=list2head;
        return listhead->next;
    }
};