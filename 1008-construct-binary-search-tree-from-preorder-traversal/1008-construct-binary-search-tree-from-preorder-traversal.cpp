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
    TreeNode* insert(TreeNode* root,int value){
       if(root==NULL){
              
          root=new TreeNode(value);
            // cout<<"came at "<<root->val<<endl;    
           return root ;
       }
        if(root->val > value){
            // cout<<"left->";
            root->left=insert(root->left,value);
        }else{
             // cout<<"right->";
            root->right=insert(root->right,value);
        }
        return root;
        
    }   
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=new TreeNode(preorder[0]);
       
         if(preorder.size()==1)return root;
        
          for(int i=1;i<preorder.size();i++){
              // cout<<root->val<<endl;
              insert(root,preorder[i]);
              // cout<<endl;
          }
      return root;
    }
};