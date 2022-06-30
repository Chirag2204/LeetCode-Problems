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
    vector<TreeNode*> ans;
    void getInorder(TreeNode *root){
        if(root){
            getInorder(root->left);
            ans.push_back(root);
            getInorder(root->right);
        }
    }
    int index=0;
    TreeNode* insert(int start,int end){
        if(start>end)return NULL;
        int mid=start+(end-start)/2;
        TreeNode* root=ans[mid];
        root->left=insert(start,mid-1);
        root->right=insert(mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return insert(0,ans.size()-1);
       
    }
};