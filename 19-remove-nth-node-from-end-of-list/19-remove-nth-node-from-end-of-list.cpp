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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *temp1=head,*temp2=head,*prev;
          int size=listSize(temp2);
        if(size==1 || n-size==0)
            return head->next ? head->next : NULL;
        int count=0;
        while(temp1!=NULL){
            count++;
            prev=temp1;
            temp1=temp1->next;
            if(count==size-n)
                break;
        }
        // ListNode *node=temp1->next;
        if(temp1->next==NULL)
            prev->next=NULL;
        else
            prev->next=temp1->next;
        delete temp1;
        return head;
    }
    
    int listSize(ListNode *head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
};