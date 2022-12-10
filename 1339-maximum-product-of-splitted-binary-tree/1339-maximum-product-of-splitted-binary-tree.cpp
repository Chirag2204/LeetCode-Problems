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
    long long ans=0;
    int mod=1e9+7;
    
    long long maxl(long long &a,long long& b){
        if(a<b)return b;
        return a;
    }
    
    int sumtree(TreeNode* root){
        if(root==NULL)return 0;
        
        int left=sumtree(root->left);
        
        int right=sumtree(root->right);
        
        return root->val+ left+ right;
    }
    
    long long solve(TreeNode* root,int &sum){
        if(root==NULL)return 0;
        
        long long left=solve(root->left,sum);
        
        long long right=solve(root->right,sum);
        // cout<<root->val<<" "<<right<<" "<<left<<" "<<sum<<endl;
        long long sum1=(sum-left)*left;
        long long sum2= (sum-right)*right;
        long long alt=maxl(sum1,sum2);
        ans=maxl(ans,alt);
        
        return root->val+ left+ right;
        
    }
    
    int maxProduct(TreeNode* root) {
        int sum=sumtree(root);
        
        solve(root,sum);
        
        return int(ans%mod);
    }
};