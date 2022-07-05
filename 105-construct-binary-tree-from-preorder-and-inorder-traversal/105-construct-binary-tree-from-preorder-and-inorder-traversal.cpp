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
    
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int& index,int start,int end){
        if(index>=inorder.size() || start>end){
            return NULL;
        }
        int x=preorder[index];
        index++;
        TreeNode* root=new TreeNode(x);//create a new node
        int position=getPosition(inorder,x);//to get position of element in inorder
        
        root->left=solve(preorder,inorder,index,start,position-1);
        root->right=solve(preorder,inorder,index,position+1,end);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return solve(preorder,inorder,preOrderIndex,0,preorder.size()-1);
    }
};