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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        map<int,int> m;
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode*,int> frontNode = q.front();
            q.pop();
            int data=frontNode.first->val;
            int lvl = frontNode.second;
            
            if(!m[lvl]){
                m[lvl]=data;
            }
            if(frontNode.first->right){
                q.push(make_pair(frontNode.first->right,lvl+1));
            }
             if(frontNode.first->left){
                q.push(make_pair(frontNode.first->left,lvl+1));
            }
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};