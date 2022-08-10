class Solution {
public:
    
    void dfs(unordered_map<int,vector<int>>& m,int node,vector<int>& visited,int dist){
        if(visited[node]!=-1)return;
        
        visited[node]=dist;
        for(auto& i: m[node]){
            dfs(m,i,visited,dist+1);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       unordered_map<int,vector<int>> m;
        int n=edges.size();
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            m[i].push_back(edges[i]);
        }
        vector<int> dis1(n,-1);
        vector<int> dis2(n,-1);
        dfs(m,node1,dis1,0);
        dfs(m,node2,dis2,0);
        
        int ans=-1,dis=INT_MAX;
        for(int i=0;i<n;i++){
            // cout<<dis1[i]<<" "<<dis2[i]<<endl;
           if(dis1[i]>=0 && dis2[i]>=0 && max(dis1[i],dis2[i])<dis){
               ans=i;
               dis=max(dis1[i],dis2[i]);
           } 
        }
        return ans;
    }
};