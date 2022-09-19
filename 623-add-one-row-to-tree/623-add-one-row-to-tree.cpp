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
    TreeNode* solve(TreeNode* root, int val, int depth){
        if(root==NULL)return NULL;
        TreeNode* left=solve(root->left,val,depth-1);
        TreeNode* right=solve(root->right,val,depth-1);
        
        if(depth==2){
            
                TreeNode* temp=left;
                root->left=new TreeNode(val);
                root->left->left=left;
            
            
                 temp=right;
                root->right=new TreeNode(val);
                root->right->right=right;
            
        }
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        return solve(root,val,depth);
    }
};