/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
  
    string serialize(TreeNode* root) {
     if(root==NULL)return "";
        
    return to_string(root->val)+"-"+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* insert(TreeNode* root,int val){
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            return temp;
        }
        
        if(val<=root->val){
            root->left=insert(root->left,val);
        }else root->right=insert(root->right,val);
        
        return root;
    }
    
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        
        string item;
        TreeNode* root=NULL;
        
        while(getline(ss,item,'-')){//get input from string stream upto char '-'
            root=insert(root,stoi(item));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;