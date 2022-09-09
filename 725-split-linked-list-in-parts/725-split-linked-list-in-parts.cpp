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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        int ineach=size/k;
        int extra=size%k;
        
        temp=head;
        vector<ListNode* > ans(k,NULL);
        ListNode* prev=NULL;
        int count=0,countnode=1;
        while(temp and count<k){
            ans[count]=temp;
            count++;
            if(count<=extra){
                countnode=0;
                while(countnode<ineach+1){
                    prev=temp;
                    temp=temp->next;
                    countnode++;
                }
            }else{
                countnode=0;
               while(countnode<ineach){
                    prev=temp;
                    temp=temp->next;
                   countnode++;
                } 
            }
            prev->next=NULL;
        }
        return ans;
    }
};