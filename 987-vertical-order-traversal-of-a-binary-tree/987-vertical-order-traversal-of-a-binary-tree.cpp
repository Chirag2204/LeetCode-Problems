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
   
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          vector<vector<int>> ans;
          if(root==NULL)
           return ans;
        
        map<int,map<int,vector<int> > > m;//horizontal dist->(level,list of nodes)
        queue<pair<TreeNode*,pair<int,int> > > q;
        
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> frontNode = q.front();
            q.pop();
            
            int hd=frontNode.second.first;
            int lvl = frontNode.second.second;
            int data=frontNode.first->val;
            
            m[hd][lvl].push_back(data);
            
            if(frontNode.first->left){
                q.push(make_pair(frontNode.first->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode.first->right){
                q.push(make_pair(frontNode.first->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i : m){
            vector<int> topush;
            for(auto j : i.second){
                sort(j.second.begin(),j.second.end());
               for(auto k: j.second){
                   topush.push_back(k);
               }
            }
            ans.push_back(topush);
        }
        return ans;
        
    }
};