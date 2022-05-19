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
    void calc(TreeNode* root,int& count){
       if(root==NULL)return;
        
        count++;
        
        calc(root->left,count);
        calc(root->right,count);
    }
    
    int countNodes(TreeNode* root) {
       int count=0;
        calc(root,count);
        return count;
    }
};