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
    stack<int> st;
   
    vector<int> ans;
    void solve(ListNode* node){
       if(node){
           solve(node->next);
           while(st.top()!=0 and node->val >= st.top())st.pop();
           
           ans.push_back(st.top());
           st.push(node->val);
       }    
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
         st.push(0);
        solve(head);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};