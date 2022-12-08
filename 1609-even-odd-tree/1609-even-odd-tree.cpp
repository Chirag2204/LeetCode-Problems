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
    bool isEvenOddTree(TreeNode* root) {
        vector<int> level;
        
        bool odd=true;
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* t =q.front();
            q.pop();
             
            if(t==NULL){
                //cout<<endl;
                odd=!odd;
                level.clear();
                if(!q.empty())q.push(NULL);
            }
            else{
                //cout<<t->val<<" ";
               if((odd and t->val%2==0) or (!odd and t->val%2))return false;
                
                if(level.size() and ((odd and level.back()>=t->val) or (!odd and level.back()<=t->val)))return false;
                
                level.push_back(t->val);
                
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
        }
        return true;
    }
};