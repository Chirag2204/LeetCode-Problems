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
    int getMax(vector<int>& nums,int start,int end){
        int max=start;
        for(int i=start;i<end;i++){
            if(nums[i]>nums[max]){
                max=i;
            }
        }
        return max;
    }
    
    TreeNode* construct(TreeNode* root,vector<int>& nums,int start,int end){
        if(start==end){
            root=NULL;
            return root;
        }
        
        int n=getMax(nums,start,end);
        
        root=new TreeNode(nums[n]);
        
        //partitioning
        // cout<<start<<" "<<n-1<<endl;
        // cout<<"left"<<endl;
        root->left=construct(root->left,nums,start,n);
        //   cout<<n+1<<" "<<end<<endl;
        // cout<<"right"<<endl;
        root->right = construct(root->right,nums,n+1,end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *root=construct(root,nums,0,nums.size());
                return root;
    }
};