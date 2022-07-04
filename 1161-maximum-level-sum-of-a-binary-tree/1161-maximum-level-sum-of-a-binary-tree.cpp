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
    int maxLevelSum(TreeNode* root) {
        long long sum=0;
        long long maxsum=INT_MIN;
        int maxlvl=1;
        int curlvl=1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* top=q.front();
            q.pop();
            if(top==NULL){
                if(sum>maxsum){
                    maxsum=sum;
                    maxlvl=curlvl;
                }
                sum=0;
                curlvl++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                
                sum+=top->val;
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
        }
        return maxlvl;
    }
};