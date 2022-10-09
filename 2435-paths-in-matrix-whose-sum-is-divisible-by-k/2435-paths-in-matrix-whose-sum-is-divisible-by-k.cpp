class Solution {
public:
    int mod=1e9+7;
    long long solve(vector<vector<int>>& grid,int x,int y,int& m,int& n,int& k,long long sum,vector<vector<vector<long long>>>& dp){
        if(x==m-1 and y==n-1){
            if(sum%k)return 0;
            return 1;
        }
        if( dp[x][y][sum]!=-1)return dp[x][y][sum];
        
        long long right=0,down=0;
     
      
        if(y<n-1){
            right=solve(grid,x,y+1,m,n,k,(sum+grid[x][y+1])%k,dp)%mod;
        }
        if(x<m-1)
            down=solve(grid,x+1,y,m,n,k,(sum+grid[x+1][y])%k,dp)%mod;
        
       
        return dp[x][y][sum]=(right+down)%mod;
        
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        long long sum=grid[0][0]%k;
       
        vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(n+1,vector<long long>(k,-1)));
     
        return (int)solve(grid,0,0,m,n,k,sum,dp);
    }
};