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
class FindElements {
public:
    vector<int> v;
    void getTree(TreeNode* root,int x){
        if(!root)return ;
        
        root->val=x;
        v.push_back(x);
        getTree(root->left,2*x+1);
        getTree(root->right,2*x+2);
    }
    
    FindElements(TreeNode* root) {
       getTree(root,0);
    }
    
    bool find(int target) {
      for(int &x:v){
          if(x==target)return true;
      }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */