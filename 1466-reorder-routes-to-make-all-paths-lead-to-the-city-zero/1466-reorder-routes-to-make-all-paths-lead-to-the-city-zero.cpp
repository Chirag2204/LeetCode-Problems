class Solution {
public:
    int solve(unordered_map<int,vector<int>>& m,vector<bool>& vis,int x){
        vis[x]=true;
        int ans=0;
        for(auto& i:m[x]){
            if(!vis[abs(i)]){
                vis[abs(i)]=true;
                ans+= solve(m,vis,abs(i))+ (i<0);
                vis[abs(i)]=false;
            }
        }
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> m;
        
        for(auto& x:connections){
            m[x[1]].push_back(x[0]);
            m[x[0]].push_back(-x[1]);//negatives need to be changed
        }
        vector<bool> vis(n);
        return solve(m,vis,0);
    }
};