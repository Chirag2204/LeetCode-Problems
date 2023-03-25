class Solution {
public:
    long long ans=0;
    
    void solve(unordered_map<int,vector<int>>& m,vector<int>& vis,int& val,int& n){
        queue<int> q;
        long long count=1;
        q.push(val);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto& x:m[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push(x);
                    count++;
                }
            }
        }
        
        ans+= count*(n-count);
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        
        for(auto& x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        
        vector<int> vis(n);
        long long count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                count=1;
                solve(m,vis,i,n);
            }
        }
        ans/=2;
        return ans;
    }
};