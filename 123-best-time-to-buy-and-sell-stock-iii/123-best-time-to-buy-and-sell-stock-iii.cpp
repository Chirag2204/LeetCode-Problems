
    class Solution {
public:
    int solve(vector<int>& prices,int index,int count,bool bought,vector<vector<vector<int>>>& dp){
        if(index>=prices.size())return 0; 
        
        if(dp[index][bought][count]!=-1)return dp[index][bought][count];
        
        if(!bought){
            int buy=0;
            if(count<2)
             buy=-prices[index] + solve(prices,index+1,count+1,true,dp);
            
            int notbuy=solve(prices,index+1,count,false,dp);
            return dp[index][bought][count]= max(buy,notbuy);
        }
        int sell=prices[index] + solve(prices,index+1,count,false,dp);
        int notsell=solve(prices,index+1,count,true,dp);
        
        return dp[index][bought][count]= max(sell,notsell);
    }
        
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
       return solve(prices,0,0,false,dp); 
    }
};
