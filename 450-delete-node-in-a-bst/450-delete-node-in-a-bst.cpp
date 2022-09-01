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
    vector<int> nums;
    void solve(TreeNode* root,int &key){
        if(root!=NULL){
            solve(root->left,key);
            if(root->val!=key)nums.push_back(root->val);
            solve(root->right,key);
        }
    }
    
 
    
    TreeNode*  insert(int start,int end){
        if(start>end)return NULL;
        
        int mid=start+(end-start)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->right=insert(mid+1,end);
        root->left=insert(start,mid-1);
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        solve(root,key);
        // cout<<nums.size()<<endl;
        // int index=0;
        return insert(0,nums.size()-1);
    }
};