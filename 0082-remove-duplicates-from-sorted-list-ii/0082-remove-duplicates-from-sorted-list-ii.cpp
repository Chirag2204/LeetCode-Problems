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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans=NULL;
        
       map<int,int> m;
       while(head){
           m[head->val]++;
           head=head->next;
       }
        
        ListNode* temp=NULL;
        for(auto& x:m){
            if(x.second==1){
                
                if(ans==NULL){
                    ans= new ListNode(x.first);
                    temp=ans;
                }else{ 
                temp->next=new ListNode(x.first);
                temp=temp->next;
               }
            }
        }
        return ans;
    }
};