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
    map<int,int> m;
    void solve(TreeNode* root){
        if(!root)return ;
        m[root->val]++;
        solve(root->left);
        solve(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        solve(root);
        int ans=1e9;
        int prev=-1,cur=-1;
        for(auto& x: m){
            if(x.second>1)return 0;
            if(prev==-1)prev=x.first;
            else {
                
                ans=min(ans,abs(x.first-prev));
                prev=x.first;
            }
        }
        return ans;
        
    }
};