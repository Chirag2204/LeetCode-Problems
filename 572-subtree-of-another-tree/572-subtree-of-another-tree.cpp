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
    bool isSame(TreeNode* s,TreeNode* t){
        if(t==NULL and s==NULL)return true;
        if(t==NULL || s==NULL)return false;
        
        return s->val==t->val and isSame(s->left,t->left) and isSame(s->right,t->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)return true;
        
        if(root==NULL)return false;
        
        if(isSame(root,subRoot))return true;
        
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        
        return left or right;
    }
};