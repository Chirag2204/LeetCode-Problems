class Solution {
public:
    int solve(vector<vector<int>>& arr,int i,int j,int &m,int &n,vector<vector<int>> &dp){
        if(i>=m || j>=n)return 0;
        
        if(arr[i][j]==1)return 0;
        
        if(i==m-1 && j==n-1)return 1;
        
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int right=solve(arr,i,j+1,m,n,dp);
        int down=solve(arr,i+1,j,m,n,dp);
        
        return dp[i][j]=right+down;
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        vector<vector<int>>dp(102,vector<int>(102,-1));
        int m=arr.size();
        int n=arr[0].size();
        return solve(arr,0,0,m,n,dp);
    }
};