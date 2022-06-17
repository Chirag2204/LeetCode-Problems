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
    int res=0;
    int solve(TreeNode* root){
        if(root==NULL)return 2;
        
        int left=solve(root->left),right=solve(root->right);
        if(left==0 || right==0){
            res++;
            return 1;
        }
        if(left==1 || right==1)return 2 ;
        else return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;
        if(solve(root)==0)ans=1;
        else ans=0;
        return ans+res;
    }
};