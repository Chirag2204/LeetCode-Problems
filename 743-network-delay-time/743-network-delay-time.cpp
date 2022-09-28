class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> m;//node node,dist
        for(auto& x:times){
            m[x[0]].push_back({x[1],x[2]});
        }
        
        vector<int> vis(n+1,-1);
        
        queue<pair<int,int>> q;// node timeofmsg
        
        q.push({k,0});
        vis[k]=0;
        int ans=-1;
        while(!q.empty()){
            int temp=q.front().first;
            int time=q.front().second;
            
           
            q.pop();
            
            for(auto& x:m[temp]){
                if(vis[x.first]==-1 or vis[x.first]>time+x.second){
                    //cout<<"came "<<x.first<<endl;
                    vis[x.first]=time+x.second;
                    q.push({x.first,x.second+time});
                }
            }
        }
        for(int i=1;i<=n;i++){
           if(vis[i]==-1)return -1;
            ans=max(ans,vis[i]);
        }
            
        
        return ans;
    }
};