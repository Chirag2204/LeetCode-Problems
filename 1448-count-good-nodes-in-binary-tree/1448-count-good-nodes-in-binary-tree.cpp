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
    stack<int> maxi;
    int count=0;
    void solve(TreeNode* root){
        if(root==NULL)return ;
        if(maxi.empty())
        maxi.push(root->val);
        else maxi.push(max(root->val,maxi.top()));
        solve(root->left);
        solve(root->right);
        if(root->val==maxi.top())count++;
        maxi.pop();
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        solve(root);
        return count;
    }
};