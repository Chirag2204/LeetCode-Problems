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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* head;
        ListNode* tail;
        ListNode* temp=list1;
        int count=0;
        while(temp!=NULL){
               count++;
               if(count==a)head=temp;
               if(count==b+2)tail=temp;
            temp=temp->next;
        }
        head->next=list2;
        ListNode* temp2=list2;
        while(temp2->next){
            temp2=temp2->next;
        }
        temp2->next=tail;
        return list1;
    }
};