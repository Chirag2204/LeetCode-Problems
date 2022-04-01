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
    pair<bool,int> fastisBalanced(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p= make_pair(true,0);
            return p;
        }
         
        pair<bool,int> left=fastisBalanced(root->left);
        pair<bool,int> right=fastisBalanced(root->right);
        
        pair<bool,int> ans;
        ans.first=left.first&&right.first&&(abs(left.second-right.second)<=1);
        ans.second=max(left.second,right.second)+1;
        
        return ans;
        
    }
    
    bool isBalanced(TreeNode* root) {
        return fastisBalanced(root).first;
    }
};