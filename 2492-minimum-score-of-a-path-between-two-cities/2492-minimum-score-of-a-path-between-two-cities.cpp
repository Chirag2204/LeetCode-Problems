class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        map<int,vector<vector<int>>> adj;
        
        for(auto& x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min heap
            vector<int> dist(n+1,1e9);
           pq.push({0,1});

           while(!pq.empty()){
               int x=pq.top().second;
               int dis=pq.top().first;
               pq.pop();

               if(dist[x]>dis){
                   dist[x]=dis;
                   for(auto& a: adj[x]){
                       pq.push({a[1],a[0]});
                   
               }
           }
          
        
    }
        int ans=1e9;
         for(int i=2;i<=n;i++)if(ans>dist[i])ans=dist[i];
        
        return ans;
    }
};