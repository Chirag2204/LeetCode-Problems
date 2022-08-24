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
    int getmaxmin(TreeNode* root,int maxi,int mini){
        if(root==NULL)return maxi-mini;
        
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        
        return max(getmaxmin(root->left,maxi,mini),getmaxmin(root->right,maxi,mini));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
         
        return getmaxmin(root,root->val,root->val);
    }
};