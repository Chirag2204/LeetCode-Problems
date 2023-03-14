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
    vector<string> nums;
    string s;
    void solve(TreeNode* root){
       if(root==NULL) return ;
       s.push_back(char(root->val + 48));
        
       if(root->left==NULL and root->right==NULL){
           nums.push_back(s);
           s.pop_back();
           return ;
       }
        solve(root->left);
        solve(root->right);
        
        s.pop_back();
       
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root);
        int sum=0;
        for(string& s: nums){
            sum+=stoi(s);
        }
        return sum;
    }
};