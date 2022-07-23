class Solution {
public:
    int solve(vector<int>&nums,int prev,int index,vector<vector<int>>& dp){
        if(index>nums.size())return 0;
        if(dp[index][prev]!=-1)return dp[index][prev];
        int include=0,notinclude=0;
        if(prev==0 || nums[index-1]>nums[prev-1]){
          include=1+solve(nums,index,index+1,dp);  
        }
          notinclude=solve(nums,prev,index+1,dp);
        
        return dp[index][prev]=max(include,notinclude);
        
        
    }
    int lengthOfLIS(vector<int>& nums) {
        cout<<nums.size()<<endl;
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+1,-1));
        return solve(nums,0,1,dp);
        
    }
};