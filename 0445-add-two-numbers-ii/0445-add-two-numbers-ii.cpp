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
   
    int carry=0;
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* ans=NULL;
        stack<int> st1;
        stack<int> st2;
        
        while(l1){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2=l2->next;
        }
        int val1=0,val2=0;
        int val=0;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        while(!st1.empty() or !st2.empty()){
            val1=0,val2=0;
            if(!st1.empty()){
                val1=st1.top();
                st1.pop();
            }
            
            if(!st2.empty()){
                val2= st2.top();
                st2.pop();
            }
            //cout<<val1<<" "<<val2<<endl;
            val=val1+val2+carry;
            carry= val>=10?1:0;
            val%=10;
            //cout<<val<<" "<<carry<<endl;
            if(prev==NULL){
                prev=new ListNode(val);
            }else{
                curr= new ListNode(val);
                curr->next=prev;
                prev=curr;
            }
        }
        if(carry)
        {
           ListNode* temp= new ListNode(1);
            temp->next=prev;
            prev=temp;
        }   
        return prev;
        
    }
};