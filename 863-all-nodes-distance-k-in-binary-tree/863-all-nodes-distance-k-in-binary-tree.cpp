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
    map<TreeNode*,TreeNode*> childparent;
  
    void pairit(TreeNode* root){
        if(root){
            if(root->left)childparent[root->left]=root;
            if(root->right)childparent[root->right]=root;
            
            pairit(root->left);
            pairit(root->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        pairit(root);
         map<TreeNode*,bool> vis;
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        vis[target]=true;
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int dist=q.front().second;
            
            if(dist==k)ans.push_back(temp->val);
            q.pop();
            
            if(temp->left and !vis[temp->left]){
                vis[temp->left]=true;
                q.push({temp->left,dist+1});
            }
            if(temp->right and !vis[temp->right]){
                vis[temp->right]=true;
                q.push({temp->right,dist+1});
            }
            if(childparent.count(temp) and !vis[childparent[temp]]){
                vis[childparent[temp]]=true;
                q.push({childparent[temp],dist+1});
            }
        }
        return ans;
    }
};