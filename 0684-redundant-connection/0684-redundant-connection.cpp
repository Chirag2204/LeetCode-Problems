class Solution {
public:
    bool dfs(map<int,vector<int>>& m,int val,vector<int>& vis,int par){
        if(vis[val])return true;
        vis[val]=1;
        for(auto& x:m[val]){
           
           if(x!=par and dfs(m,x,vis,val))return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> vis(n+1,0);
        map<int,vector<int>> m;
        for(auto& x:edges){
            for(int i=1;i<=n;i++)vis[i]=0;
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
            if(dfs(m,x[0],vis,-1))return x;
            
        }
    
        return {};
    }
};