class Solution {
public:
    int solve(vector<int>& nums,int index,int target,vector<vector<int>>&  dp){
        
        if(target==0)return 1;
        if(index>=nums.size())return 0;
        if(dp[index][target]!=-1)return dp[index][target];
        int inc=0,notinc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                inc+=solve(nums,i,target-nums[i],dp);
            }
           
        }
        return dp[index][target]=inc;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};