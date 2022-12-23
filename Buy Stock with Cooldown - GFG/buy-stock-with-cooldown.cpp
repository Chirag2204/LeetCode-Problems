//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maxl(long long& a,long long& b){
        if(a<b)return b;
        return a;
    }
    long long solve(vector<long long>& prices,int index,bool bought,vector<vector<long long>>& dp){
        if(index>=prices.size())return 0;
        
        if(dp[index][bought]!=-1)return dp[index][bought];
        
        if(!bought){
            long long buy=-prices[index]+solve(prices,index+1,true,dp);
            long long notbuy=solve(prices,index+1,false,dp);
            return dp[index][bought]=maxl(buy,notbuy);
        }
            long long sell=prices[index]+solve(prices,index+2,false,dp);
            long long notsell=solve(prices,index+1,true,dp);
            return dp[index][bought]=maxl(sell,notsell);
        
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
     vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
     return solve(prices,0,false,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends