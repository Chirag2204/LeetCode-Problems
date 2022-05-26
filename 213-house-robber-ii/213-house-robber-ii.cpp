class Solution {
public:
    int solve(vector<int>& nums,int index,int end,vector<int>& dp){
       if(index>=end)return 0;
        
        if(dp[index]!=-1)return dp[index];
        
        int pick=nums[index]+solve(nums,index+2,end,dp);
        
        int notpick=solve(nums,index+1,end,dp);
        
        return dp[index]=max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
       vector<int> dp(102,-1);
        int pick=nums[0]+solve(nums,2,nums.size()-1,dp);
        vector<int> dp1(102,-1);
        int notpick=solve(nums,1,nums.size(),dp1);
       
        return max(pick,notpick);
    }
};