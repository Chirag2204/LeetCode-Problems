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
    int count=0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL)return make_pair(0,0);
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        if((root->val+left.first+right.first)/(1+left.second+right.second)==root->val)count++;
        
        return make_pair(root->val+left.first+right.first,1+left.second+right.second);
    }
    
    int averageOfSubtree(TreeNode* root) {
      solve(root);
      
        return count;
        
    }
};