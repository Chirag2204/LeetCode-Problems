class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<pair<bool,int>>> m;
        
        for(auto& x: redEdges){
            m[x[0]].push_back({true,x[1]});
        }
        for(auto& x: blueEdges){
            m[x[0]].push_back({false,x[1]});
        }
        
        vector<int> ans(n,1e9);
        
        queue<pair<int,pair<bool,int>>> q;
        vector<int> vis(n,0);
        
        q.push({0,{true,0}});
        q.push({0,{false,0}});
        
        while(!q.empty()){
            int node=q.front().first;
            bool color= q.front().second.first;
            int dist= q.front().second.second;
            q.pop();
            ans[node]=min(ans[node],dist);
            if(vis[node])continue;
            //vis[node]=1;
            for(auto& x: m[node]){
                if(x.first!=color and x.second!=-1){
                    //vis[x.second]=1;
                    q.push({x.second,{x.first,dist+1}});
                    x.second=-1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(ans[i]==1e9)ans[i]=-1;
        }
        
        return ans;
    }
};