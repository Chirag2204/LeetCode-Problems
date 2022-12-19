class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)return true;
        vector<int> vis(n);
        
        map<int,vector<int>> m;
        
        for(auto& x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source]=1;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            for(auto& v:m[x]){
                if(v==destination)return true;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        return false;
    }
};