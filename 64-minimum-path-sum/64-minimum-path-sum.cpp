class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int& m,int& n,vector<vector<int>>& dp){
        if(i>=m || j>=n)return 1000;
        
        if(i==m-1 && j==n-1)return grid[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=grid[i][j] + solve(grid,i,j+1,m,n,dp);
        int down=grid[i][j]+solve(grid,i+1,j,m,n,dp);
        
        return dp[i][j]=min(right,down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(202,vector<int>(202,-1));
        int m=grid.size();
        int n=grid[0].size();
        return solve(grid,0,0,m,n,dp);
    }
};