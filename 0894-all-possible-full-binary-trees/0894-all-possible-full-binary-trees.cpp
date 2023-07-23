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
    unordered_map<int,vector<TreeNode*>> m;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode* >ans;
        if(n%2==0)return ans;
        
        if(n==1){
            ans.push_back(new TreeNode(0));
            m[1]=ans;
            return ans;
        }
        if(m.count(n))return m[n];
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left= allPossibleFBT(i);
            vector<TreeNode*> right= allPossibleFBT(n-1-i);
            //cout<<n<<" "<<"here"<<endl;
            for(int x=0;x<left.size();x++){
                for(int y=0;y<right.size();y++){
                    TreeNode* temp= new TreeNode(0);
                    temp->left= left[x];
                    temp->right= right[y];
                    ans.push_back(temp);
                }
            }
        }
        return m[n]= ans;
        
    }
};