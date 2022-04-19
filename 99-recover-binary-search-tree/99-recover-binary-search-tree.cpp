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
    void inorder(TreeNode* root,vector<int>& ans){
       if(root){
           inorder(root->left,ans);
       
           ans.push_back(root->val);
           inorder(root->right,ans);
       } 
    }
    int index=0;
    void place(TreeNode* root,vector<int>& ans){
         if(root){
           place(root->left,ans);
             
           root->val=ans[index];
            index++;
           place(root->right,ans);
       } 
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        cout<<endl;
        sort(ans.begin(),ans.end());
        place(root,ans);
    }
};