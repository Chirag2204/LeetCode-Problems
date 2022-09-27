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
    int getheight(TreeNode* root){
        if(root==NULL)return 0;
        
        int left=getheight(root->left);
        int right=getheight(root->right);
        
        return max(left,right)+1;
    }
    
    void place(TreeNode* root,vector<vector<string>>& ans,int lvl,int s,int e){
        if(root){
            int mid=s+(e-s)/2;
        
            ans[lvl][mid]=to_string(root->val);

            place(root->left,ans,lvl+1,s,mid-1);
            place(root->right,ans,lvl+1,mid+1,e);
        }
        
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
       int rows=getheight(root);
        //cout<<rows<<endl;
        int cols=pow(2,rows)-1;
        
        vector<vector<string>> ans(rows,vector<string>(cols,""));
        place(root,ans,0,0,cols-1);
        
        return ans;
    }
};