class Solution {
public:
    int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>& dp){
        if(row>=matrix.size())return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int suml=10000,summ=10000,sumr=10000;
        if(col>0)suml=matrix[row][col]+solve(matrix,row+1,col-1,dp);
        if(col<matrix[0].size()-1)sumr=matrix[row][col]+solve(matrix,row+1,col+1,dp);
        summ=matrix[row][col]+solve(matrix,row+1,col,dp);
        
        return dp[row][col]= min(summ,min(sumr,suml));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp (matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        int ans=10000;
        for(int i=0;i<matrix.size();i++){
            ans=min(ans,solve(matrix,0,i,dp));
        }
        return ans;
    }
};