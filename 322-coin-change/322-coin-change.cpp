class Solution {
public:
   int solve(vector<int>& coins,vector<vector<int> >& dp,int amount,int index){
   
        if(amount<0 || index>=coins.size())return 100000;
       
       if(amount==0)return 0;
       
       if(dp[index][amount]!=-1)return dp[index][amount];
       
       int nottake=solve(coins,dp,amount,index+1);
       int take=1+solve(coins,dp,amount-coins[index],index);
       
       return dp[index][amount]=min(nottake,take);
  
    }
    
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(10002,-1));
       
       int ans= solve(coins,dp,amount,0);
        if(ans>=100000)return -1;
        return ans;
        
    }
};