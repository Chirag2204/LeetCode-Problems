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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* head,TreeNode* root){
         if(head==NULL)return true;
         if(root==NULL)return false;
         
        
        bool right=solve(head->next,root->right);
        bool left=solve(head->next,root->left);
        
        return  head->val==root->val && (right||left);
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
         if(head==NULL)return true;
        if(root==NULL)return false;
       
        
        return solve(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};