class Solution {
public:
    int ans=0;
    vector<int> vis;
    bool dfs(int val,map<int,vector<int>>& m,vector<bool>& hasApple){
        if(vis[val])return  false;
        vis[val]=1;
       bool ret=false;
        if(hasApple[val])ret=true;
       for(auto& x:m[val]){
           bool val=dfs(x,m,hasApple);
           if(val){
            ans+=2;
        }
           ret=val or ret ;
           
       }
      
        
        return ret;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,vector<int>> m;
        
        for(auto& x:edges)m[x[0]].push_back(x[1]);
        for(auto& x:edges)m[x[1]].push_back(x[0]);
        vis.resize(n,0);
        dfs(0,m,hasApple);
        return ans;
    }
};