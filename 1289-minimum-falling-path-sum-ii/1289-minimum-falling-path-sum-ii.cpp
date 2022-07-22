class Solution {
public:
    int solve(vector<vector<int>>& matrix,int row,int prev,vector<vector<int>>& dp){
        if(row>=matrix.size())return 0;
        if(dp[row][prev]!=-1)return dp[row][prev];
        int sum=1000000;
        for(int i=0;i<matrix[0].size();i++){
            if(i!=prev)
            sum=min(sum,matrix[row][i]+solve(matrix,row+1,i,dp));
        }
        
        return dp[row][prev]= sum;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp (matrix.size()+1,vector<int>(202,-1));

        return solve(matrix,0,201,dp);
    }
};