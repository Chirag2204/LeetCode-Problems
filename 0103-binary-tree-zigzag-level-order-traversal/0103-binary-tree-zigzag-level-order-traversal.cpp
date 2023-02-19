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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       	vector<vector<int>> ans;
    	if(root==NULL)
    	  return ans;
    	bool lefttoright=true;
    	queue<TreeNode*> q;
    	q.push(root);
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> topush(size);
    	    
    	   
    	    for(int i=0;i<size;i++){
    	         TreeNode* front=q.front();
    	         q.pop();
    	       int index=lefttoright?i:size-i-1;
    	       topush[index]=front->val;
    	       
    	       if(front->left)
    	      q.push(front->left);
    	      
    	    if(front->right)
    	      q.push(front->right);
    	    }
    	    lefttoright=!lefttoright;
    	    ans.push_back(topush);
    	    
    	}
    	return ans;
        
    }
};