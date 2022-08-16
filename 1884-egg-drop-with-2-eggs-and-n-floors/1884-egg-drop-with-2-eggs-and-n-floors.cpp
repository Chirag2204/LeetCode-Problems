class Solution {
public:
    int solve(int n,int eggs,vector<vector<int>>& dp){
        if(n<=1 || eggs==1)return n;
        if(dp[n][eggs]!=-1)return dp[n][eggs];
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            int broke=1+solve(i-1,eggs-1,dp);
            int notbreak=1+solve(n-i,eggs,dp);
            
            ans=min(ans,max(broke,notbreak));
        }
        return dp[n][eggs]=ans;
    }
    
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(n,2,dp);
    }
};