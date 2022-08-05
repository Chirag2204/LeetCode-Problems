class Solution {
public:
    int solve(vector<int>& nums,int index,int mod,vector<vector<int>>& dp){
        if(index>=nums.size()){
            if(mod==0)return 0;
            return -100000;
        }
        
        if(dp[index][mod]!=-1)return dp[index][mod];
        
        int inc=nums[index]+solve(nums,index+1,(nums[index]+mod)%3,dp);
        int notinc=solve(nums,index+1,mod,dp);
        
        return dp[index][mod]=max(inc,notinc);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp (nums.size()+1,vector<int>(3,-1));
       
        return solve(nums,0,0,dp);
    }
};