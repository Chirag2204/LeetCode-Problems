class Solution {
public:
    vector<vector<int>> moves{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    bool isValid(int x,int y,int size){
        //cout<<size<<endl;
        return x>=0 and x<size and y>=0 and y<size;
    }
   
    double solve(int x,int y,int k,int& n,vector<vector<vector<double>>>& dp){
        if(k==0)return 1;
        if(dp[x][y][k]!=-1)return dp[x][y][k];
        double prob=0;
        
        for(auto& nums:moves){
           // cout<<k<<" here"<<endl;
                if(isValid(x+nums[0],y+nums[1],n)){
                    
                    prob += 0.125 * solve(x+nums[0],y+nums[1],k-1,n,dp);
                }
            }
        return dp[x][y][k]= prob;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>  dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(row,column,k,n,dp);
    }
};