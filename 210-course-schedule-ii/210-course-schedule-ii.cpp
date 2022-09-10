class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
         vector<int> empty;
         vector<int> ans;
	    vector<int> inorder(N,0);
	    map<int,vector<int>> m;
	    
	     for(auto& x:pre){
	         inorder[x[0]]++;
	         m[x[1]].push_back(x[0]);
	     }
	     
	     queue<int> q;
	     for(int i=0;i<N;i++){
	         if(inorder[i]==0)q.push(i);
	     }
	     int count=N;
	     while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        ans.push_back(t);
	        count--;
	        for(int &i:m[t]){
	            inorder[i]--;
	            if(inorder[i]==0)q.push(i);
	        }
	        
	     }
	     if(count!=0)return empty;
	     
	    
	     return ans;
    }
};