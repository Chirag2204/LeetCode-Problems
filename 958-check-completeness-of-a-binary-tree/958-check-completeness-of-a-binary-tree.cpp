/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool solve(TreeNode *root) {
           queue<TreeNode*> q;
            bool pushednull=false;
            q.push(root);
            while(!q.empty()){
                TreeNode* t=q.front();
               
                q.pop();
                // if(t)
                //  cout<<t->val<<"->"<<q.size()<<" ";
                if(t==NULL){
                    if(!q.empty())return false;
                    
                }else{
                    if(t->left){
                       q.push(t->left);  
                    }else{
                        
                        if(!pushednull)q.push(NULL);
                        pushednull=true;
                    }
                    if(t->right){
                       q.push(t->right);  
                    }else{
                        if(!pushednull)q.push(NULL);
                        pushednull=true;
                    }
                    
                }
            }
            return true;
            
        }
    
        bool isCompleteTree(TreeNode *root) {
            return solve(root);
           
        }
};