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
      int getPosition(vector<int>& inorder,int& x){
        if(m.count(x))return m[x];
        return -1;
    }
    
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int& index,int start,int end){
        if(index<0 || start>end){
            return NULL;
        }
        int x=postorder[index];
        index--;
        TreeNode* root= new TreeNode(x);
        int position =  getPosition(inorder,x);
        
        root->right=solve(inorder,postorder,index,position+1,end);
        root->left=solve(inorder,postorder,index,start,position-1);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        return solve(inorder,postorder,postIndex,0,inorder.size()-1);
    }
};