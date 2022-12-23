class Solution {
public:
    int solve(vector<int> &prices,int index,bool bought,vector<vector<int>>& dp){
        if(index>=prices.size())return 0;
        if(dp[index][bought]!=-1)return dp[index][bought];
        
        if(!bought){
            int buy=-prices[index]+solve(prices,index+1,true,dp);
            int notbuy=solve(prices,index+1,false,dp);
            return dp[index][bought]=max(buy,notbuy);
        }
        
        int sell=prices[index]+solve(prices,index+2,false,dp);
        int notsell=solve(prices,index+1,true,dp);
        
        return dp[index][bought]=max(sell,notsell);
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,false,dp);
    }
};