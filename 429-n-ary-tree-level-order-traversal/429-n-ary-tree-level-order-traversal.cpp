/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> topush;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp==NULL){
                ans.push_back(topush);
                 topush.clear();
                if(!q.empty()){
                    q.push(NULL);
                  }
            }else{
                topush.push_back(temp->val);
               
                    for(auto& x:temp->children){
                        q.push(x);
                    }
                
            }
            
        }
        return ans;
    }
};