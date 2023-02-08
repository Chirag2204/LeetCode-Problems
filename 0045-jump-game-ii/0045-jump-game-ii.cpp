class Solution {
public:
    
    
    int solve(vector<int>& nums,int index,vector<int>& dp){
        if(index>=nums.size()-1){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int minjump=10005;
        for(int i=1;i<=nums[index];i++){
           if(index+i<nums.size())
           minjump=min(minjump,1+solve(nums,index+i,dp));
        }
       
        return dp[index]=minjump;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(10002,-1);
        return solve(nums,0,dp);
    }
    
};