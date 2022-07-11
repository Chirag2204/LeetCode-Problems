class Solution {
public:
    int solve(vector<int>& coins,int amount,int index,vector<vector<int>>& dp){
        if(amount==0)return 1;
        
        if(index>=coins.size()-1){
            if(amount%coins[index]==0)return 1;
            return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int notinclude=solve(coins,amount,index+1,dp);
        
        int include=0;
        if(amount>=coins[index])
            include=solve(coins,amount-coins[index],index,dp);
        
        return dp[index][amount]=include+notinclude;
        
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        
        return solve(coins,amount,0,dp);
    }
};