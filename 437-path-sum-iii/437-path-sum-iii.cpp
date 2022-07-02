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
    void solve(TreeNode* root,vector<int> path,int& k,int& count){
        if(root==NULL)return ;
        
        path.push_back(root->val);
        
        solve(root->left,path,k,count);
        solve(root->right,path,k,count);
        long long sum=0,n=path.size();
        for(int i=n-1;i>=0;i--){
            sum+=path[i];
            if(sum==k)count++;
        }
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int k) {
        int count=0;
        vector<int> path;
        solve(root,path,k,count);
        return count;
    }
};