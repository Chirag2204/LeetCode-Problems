class Solution {
public:
    bool solve(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
        if(target==0)return true;
        if(target<0 || index>=nums.size())return false;
        if(dp[index][target]!=-1)return dp[index][target];
        
        bool pick=solve(nums,index+1,target-nums[index],dp);
        
        bool notpick=solve(nums,index+1,target,dp);
        return dp[index][target]=pick || notpick;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int& i:nums){
           sum+=i;
        }
        if(sum%2)return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,0,sum/2,dp);
    }
};