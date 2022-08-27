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
    long long maxi(long long a,long long b){
        if(a>b)return a;
        return b;
    }
    
 
    int widthOfBinaryTree(TreeNode* root) {
        
        unordered_map<long long,vector<long long>> m;
        if(root->left==NULL and root->right==NULL)return 1;
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        q.push({NULL,-1});
        int lvl=0;
        vector<long long> temp;
        int lvlstart=0;
        while(!q.empty()){
            pair<TreeNode*,long long> t=q.front();
            q.pop();
            
            if(t.first==NULL){
               m[lvl]=temp;
                lvl++;
                temp.clear();
                if(!q.empty())q.push({NULL,-1});
            }else{
                TreeNode* node = t.first;
                long long index=t.second;
                if(temp.size()==0)lvlstart=index;
                temp.push_back(index);
                if(node->left)q.push({node->left,2*index+1-lvlstart});
                if(node->right)q.push({node->right,2*index+2-lvlstart});
            }
            
        }
        int ans=1;
        for(auto& x:m){
            long long mx=LONG_MIN,mn=LONG_MAX;
            for(long long& i:x.second){
                mx=max(mx,i);
                mn=min(mn,i);
            }
            ans=maxi(ans,mx-mn+1);
        }
        
        return (int)ans;
    }
};