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
    int sum=1;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL)return {0,0};
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        pair<int,int> ans;
        ans.first=root->val;
        ans.second=1;
        if(left.first==root->val and right.first==root->val){
           ans.second+=max(left.second,right.second); 
            sum=max(sum,left.second+right.second+1);
        }    
        else if(right.first==root->val)
            ans.second+=right.second;
        else if(left.first==root->val)
            ans.second+=left.second;
        sum=max(sum,ans.second);
        return ans;
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        
        return sum-1;
    }
};