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
    int pairSum(ListNode* head) {
        vector<int> ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        int sum=0;
        int i=0,j=ans.size()-1;
        while(i<=j){
            int val=ans[i]+ans[j];
            sum=max(sum,val);
            i++;
            j--;
        }
        return sum;
    }
};