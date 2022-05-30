class Solution {
public:
    int solve(vector<vector<int>>& triangle,int row,int prev,vector<vector<int>>& dp){
        if(row>=triangle.size())return 0;
        
        if(dp[row][prev]!=-1)return dp[row][prev];
        
        int path1=triangle[row][prev]+solve(triangle,row+1,prev,dp);
   
         int path2=triangle[row][prev+1] + solve(triangle,row+1,prev+1,dp);
        
        return dp[row][prev]=min(path1,path2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(202,vector<int>(202,-1));
        
        return triangle[0][0] + solve(triangle,1,0,dp);
    }
};