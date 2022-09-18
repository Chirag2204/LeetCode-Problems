class Solution {
public:
    void dfs(map<int,vector<int>>& m,int val,vector<int>& nums,vector<int> vis){
        if(m.count(val)){
            queue<int> q;
            for(int& i:m[val]){
                    if(!vis[i]){
                        vis[i]=1;
                        q.push(i);
                    }
                }
            vis[val]=1;
            while(!q.empty()){
                int t=q.front();
                q.pop();
                nums.push_back(t);
                vis[t]=1;
                for(int& i:m[t]){
                    if(!vis[i]){
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        map<int,vector<int>> m;
        vector<int> vis(n,0);
        //store in it the reverse links
        
        for(int i=0;i<edges.size();i++){
            m[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
           dfs(m,i,ans[i],vis); 
            sort(ans[i].begin(),ans[i].end());
        }
        
        return ans;
    }
};