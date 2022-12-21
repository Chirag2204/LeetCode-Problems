class Solution {
public:
    bool bfs(map<int,vector<int>>& graph,vector<int>& vis,int& val,int& c){
        queue<pair<int,int>> q;
        q.push({val,c});
        while(!q.empty()){
            int x=q.front().first;
            int color=q.front().second;
            q.pop();
            vis[x]=color;
            color=!color;
            for(int& i:graph[x]){
                if(vis[i]!=-1){
                    if(vis[i]!=color)return false;
                }else{
                    vis[i]=color;
                    q.push({i,color});
                }
            }
        }
        return true;
    }
     
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
         map<int,vector<int>> m;
        
        
        for(auto& x:dislikes){
            m[x[0]].push_back(x[1]);
             m[x[1]].push_back(x[0]);
           
        }
        vector<int> vis(n+1,-1);
        int color=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
          
                if(!bfs(m,vis,i,color))return false;
            }
            
        }
        return true;
    }
};