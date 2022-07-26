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
    TreeNode* findLCA(TreeNode* root,int& s,int& t){
        if(root==NULL)return NULL;
        
        if(root->val==s || root->val==t)return root;
        
        TreeNode* left=findLCA(root->left,s,t);
         TreeNode* right=findLCA(root->right,s,t);
        
        if(left!=NULL && right!=NULL)return root;
        if(left && right==NULL)return left;
        if(left==NULL && right)return right;
        return NULL;
    }
    TreeNode* findkey(TreeNode* root,int &key,string& path){
         if(root==NULL)return NULL;
        
        if(root->val==key)return root;
        TreeNode* left=findkey(root->left,key,path);
         TreeNode* right=findkey(root->right,key,path);
        
        // if(left==NULL && right==NULL)return root;
        if(left!=NULL && right==NULL){
            path.push_back('L');
            return left;
        }
        if(left==NULL && right!=NULL)
        {
            path.push_back('R');
            return right;
        }
        return NULL;
        
    }
    
    string getDirections(TreeNode* root, int s, int t) {
        TreeNode* lca=findLCA(root,s,t);
        
        string ans1="",ans2="";
        cout<<lca->val<<endl;
        findkey(lca,s,ans1);
        findkey(lca,t,ans2);
        for(int i=0;i<ans1.length();i++)ans1[i]='U';
        reverse(ans2.begin(),ans2.end());
        return ans1+ans2;
    }
};