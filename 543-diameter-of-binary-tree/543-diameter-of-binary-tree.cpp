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
    //advance approach
//     pair<int,int> diameterFast(TreeNode* root){
//         if(root==NULL){
//             pair<int,int> p=make_pair(0,0);
//             return p;
//         }
//         //pair store diameter at first and height at second
//         pair<int,int> left= diameterFast(root->left);
//         pair<int,int> right= diameterFast(root->right);
        
//         int op1=left.first;//left diameter
//         int op2=right.first;//right diameter
//         int op3=left.second + right.second + 1;
        
//        pair<int,int> ans;
//         ans.first=max(op1,max(op2,op3));
//         ans.second=max(left.second,right.second)+1;
        
//         return ans;
//     }
    
    //basic approach
    int height(TreeNode* root){
        if(root==NULL)return 0;
        
        int left=height(root->left);
        int right=height(root->right);
        
        return max(left,right)+1;
    }
     int diameter(TreeNode* root) {
        if(root==NULL)return 0;
        
        int op1=diameter(root->left);
        
        int op2=diameter(root->right);
        
        int op3=height(root->left)+height(root->right)+1;
        
        return max(op1,max(op2,op3));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
  
        return diameter(root)-1;
    }
};