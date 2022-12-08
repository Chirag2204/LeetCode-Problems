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
    void insert(TreeNode* root,vector<int>& nums){
        if(root==NULL)return ;
        
        if(root->left==NULL and root->right==NULL){
            nums.push_back(root->val);
            return ;
        }
        
        insert(root->left,nums);
        insert(root->right,nums);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1,nums2;
        
        insert(root1,nums1);
        insert(root2,nums2);
        
        return nums1==nums2;
    }
};