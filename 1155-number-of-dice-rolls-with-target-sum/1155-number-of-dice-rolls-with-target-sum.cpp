class Solution {
public:
    int mod=1e9+7;
    int solve(int row,int& k,int target,vector<vector<int>>& dp){
        if(row==0){
            if(target==0)return 1;
            return 0;
        }
        if(target<=0)return 0;
        if(dp[row][target]!=-1)return dp[row][target];
        
        long long ways=0;
        for(int i=1;i<=k;i++){
            ways+=solve(row-1,k,target-i,dp);
            ways%=mod;
        }
        return dp[row][target] = (int)(ways)%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp)%mod;
    }
};