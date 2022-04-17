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
    void solve(TreeNode* root,vector<int>& st){
        if(root==NULL){
            return;
        }
        solve(root->left,st);
        st.push_back(root->val);
        solve(root->right,st);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> st;
        solve(root,st);
        TreeNode *temp=new TreeNode(0);
        TreeNode *cur=temp;
        for(auto i : st){
           cur->right=new TreeNode(i);
            cur=cur->right;
        }
        return temp->right;
    }
};