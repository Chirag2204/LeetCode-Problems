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
    int count=0;
    bool ispal(map<int,int>& m){
        int c=0;
        for(auto& x:m){
            if(x.second%2){
                if(c==1)return false;
                c++;
            }
        }
        return true;
    }
    
    void checkpath(TreeNode* root,map<int,int>& m){
       
            m[root->val]++;
           if(root->left==NULL and root->right==NULL){
               if(ispal(m))count++;
               m[root->val]--;
               return ;
           }
            if(root->left)checkpath(root->left,m);
            if(root->right)checkpath(root->right,m);
            m[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> m;//num , count
        checkpath(root,m);
        return count;
    }
};