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
    int solve(TreeNode* root){
        if(root==NULL)return 0;
        
        int left=0,right=0;
        left=1+solve(root->left);
        right= 1+solve(root->right);
        
         if(left==1)return right;
        if(right==1)return left;
        
        return min(left,right);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int left=1+solve(root->left);
        
        int right=1+ solve(root->right);
         if(left==1)return right;
        if(right==1)return left;
        
        return min(left,right);
    }
};