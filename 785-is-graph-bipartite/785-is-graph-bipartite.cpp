class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &vis,int val,int c){
        
      
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
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        int color=0;
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
          
                if(!bfs(graph,vis,i,color))return false;
            }
            color=!color;
        }
        return true;
    }
};