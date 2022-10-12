class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
       map<int,vector<int>> m;// src , distnace of point from sourse
        
        map<int,vector<pair<int,int>>> m1;//src node,dist
        
        for(auto& x:edges){
            m1[x[0]].push_back({x[1],x[2]});
            m1[x[1]].push_back({x[0],x[2]});
        }
        
        vector<int> dist(n,1e9);
        
        for(int i=0;i<n;i++){
            queue<pair<int,int>> q;
            q.push({i,0});
            
            while(!q.empty()){
                int x=q.front().first;
                int dis=q.front().second;
                
                q.pop();
                
                if(dist[x]>dis){
                    dist[x]=dis;
                    for(auto& a:m1[x]){
                        q.push({a.first,dis+a.second});
                    }
                }
            }
            m[i]=dist;
            for(int i=0;i<n;i++)dist[i]=1e9;
        }
        int ans=0;
        int mn=1e9;
        for(auto& x:m){
            int count=0;
            //cout<<x.first<<endl;
            for(int& i:x.second){
                //cout<<i<<" ";
                if(i<=t and i>0)count++;
            }
            //cout<<endl;
            //cout<<count<<endl;
            if(count<=mn){
                ans=x.first;
                mn=count;
            }
        }
        return ans;
    }
};