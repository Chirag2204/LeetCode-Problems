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
    void solve(TreeNode* root,int target,vector<int> topush,vector<vector<int>>& ans){
        if(root->left==NULL && root->right==NULL){
            if(target==0)
                ans.push_back(topush);
            return ;
        }
        
        
        if(root->left){
            topush.push_back(root->left->val);
            solve(root->left,target-root->left->val,topush,ans);
            topush.pop_back();
        }
        if(root->right){
            topush.push_back(root->right->val);
            solve(root->right,target-root->right->val,topush,ans);
            topush.pop_back();
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
        if(root==NULL)return ans;
        vector<int> topush;
        topush.push_back(root->val);
       solve(root,targetSum-root->val,topush,ans);
        return ans;
    }
};