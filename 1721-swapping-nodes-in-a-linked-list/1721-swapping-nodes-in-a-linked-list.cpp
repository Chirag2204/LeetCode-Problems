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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode *node1,*node2,*temp=head;
        int swap;
        int count=0;
        int size=listSize(head);
        if(size==1)
            return temp;
        
        while(temp!=NULL){
            count++;
            if(count==size-k+1){
                node2=temp;
            }
            if(count==k){
                node1=temp;
            }
            temp=temp->next;
            
        }
        cout<<node1->val<<","<<node2->val;
        swap=node1->val;
        node1->val=node2->val;
        node2->val=swap;
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