class Solution {
public:
    bool bfs(map<int,vector<int>>& m,int& start,int& end,int& n){
        vector<int> vis(n,0);
        if(start==end)return true;
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            
            for(int& i:m[temp]){
                if(!vis[i]){
                    vis[i]=1;
                    if(i==end)return true;
                    q.push(i);
                }
            }
        }
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        map<int,vector<int>> m;
        for(auto& x:pre){
            m[x[0]].push_back(x[1]);
        }
        vector<bool> ans;
        for(auto& x:queries){
            ans.push_back(bfs(m,x[0],x[1],n));
        }
        return ans;
    }
};