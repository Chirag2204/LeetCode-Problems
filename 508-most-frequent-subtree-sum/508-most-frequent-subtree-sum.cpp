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
    unordered_map<int,int> m;
    int rootsum(TreeNode* root){
        if(root==NULL)return 0;
        int left=rootsum(root->left);
        int right=rootsum(root->right);
        int sum=root->val+left+right;
        m[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int s=rootsum(root);
      
        int mx=0;
        for(auto& x:m){
            if(x.second>mx)mx=x.second;
        }
        cout<<mx<<endl;
        vector<int> ans;
        for(auto& x:m){
            if(mx==x.second){
                ans.push_back(x.first);
            }
            
        }
        return ans;
    }
};