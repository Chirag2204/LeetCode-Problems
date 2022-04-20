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
class BSTIterator {
public:
    void inorder(TreeNode *root){
        if(root){
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    BSTIterator(TreeNode* root) {
       inorder(root); 
    }
    vector<int>ans;
    int index=0;
    
    int next() {
        int x= ans[index];
        index++;
        return x;
    }
    
    bool hasNext() {
        return index<ans.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */