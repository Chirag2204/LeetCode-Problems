/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* clone, TreeNode* target)     {
        if(original==NULL)
            return NULL;
        if(original==target)
            return clone;
        TreeNode* left = getTargetCopy(original->left,clone->left,target);
       
        TreeNode* right = getTargetCopy(original->right,clone->right,target);
         if(left)return left;
         else return right;
    }
};