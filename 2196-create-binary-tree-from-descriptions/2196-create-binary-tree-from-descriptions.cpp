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
    TreeNode* create(unordered_map<int,pair<int,int>>& m,int val){
        if(val==0){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(val);
        root->left=create(m,m[val].first);
        root->right=create(m,m[val].second);
        
        return root;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int ,pair< int,int>> m;
        unordered_set<int> s;
        int start=0;
        for(int i=0;i<desc.size();i++){
            if(desc[i][2]==1){
                m[desc[i][0]].first=desc[i][1];
            }else{
                m[desc[i][0]].second=desc[i][1];
            }
            s.insert(desc[i][1]);
            
        }
        for(int i=0;i<desc.size();i++){
            if(!s.count(desc[i][0])){
                start=desc[i][0];
                break;
            }
            
        }
        TreeNode* root=create(m,start);
        return root;
    }
};