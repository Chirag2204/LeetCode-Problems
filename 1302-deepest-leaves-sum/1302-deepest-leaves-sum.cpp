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
    int getHeight(TreeNode* root){
        if(root==NULL)
            return -1;
        else{
            int ldepth=getHeight(root->left);
            int rdepth=getHeight(root->right);
            
            return max(ldepth+1,rdepth+1);
        }
        
    }
    void getSum(TreeNode* root,int& sum,int h,int maxh){
        if(root!=NULL){
            if(root->left==NULL && root->right==NULL && h==maxh ){
                cout<<root->val<<" ";
                sum+=root->val;
            }
            getSum(root->left,sum,h+1,maxh);
            getSum(root->right,sum,h+1,maxh);
        }
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
       int sum=0;
        int maxh=getHeight(root);
        getSum(root,sum,0,maxh);
        return sum;
    }
};