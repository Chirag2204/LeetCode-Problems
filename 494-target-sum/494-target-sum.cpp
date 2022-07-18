class Solution {
public:
    int solve(vector<int>& nums,int index,int target,vector<vector<int>>& dp){

        if(index==nums.size()-1){
            if(target==0 && nums[index]==0)return 2;
            if(target==0 || nums[index]==target)return 1;
            return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        
        long long notinclude=solve(nums,index+1,target,dp);
        long long include=0;
        if(nums[index]<=target)include=solve(nums,index+1,target-nums[index],dp);
        
        return dp[index][target]=(include+notinclude)%1000000007;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
       long long sum=0;
        for(int& i:nums)sum+=i;
        int num=sum-target;
        if(num<0 || num%2)return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,0,num/2,dp);
    }
};