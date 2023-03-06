class Solution {
public:
    int mod=1e9+7;
    int solve(vector<vector<int>>& types,int index,int sum,int& target,vector<vector<int>>& dp){
        if(sum==target)return 1;
        if(sum>target)return 0;
        
        if(index==types.size())return sum==target;
        if(dp[sum][index]!=-1)return dp[sum][index];
        
        int include=0,notinclude=0;
        
        for(int i=1;i<=types[index][0];i++){
            include= (include+ solve(types,index+1,sum + i*types[index][1],target,dp))%mod;
        }
        notinclude= solve(types,index+1,sum,target,dp)%mod;
        
        return dp[sum][index]=(include+notinclude)%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
       vector<vector<int>> dp(target+100,vector<int>(51,-1));
        
        return solve(types,0,0,target,dp);
    }
};