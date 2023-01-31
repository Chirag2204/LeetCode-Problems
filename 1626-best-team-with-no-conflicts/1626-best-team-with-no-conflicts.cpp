class Solution {
public:
    int solve(vector<pair<int,int>>& nums,int index,int prev,vector<vector<int>>& dp){
       if(index>nums.size())return 0;
        
        if(dp[index][prev]!=-1)return dp[index][prev];
        
        int include=0,notinclude=0;
        
        if(prev ==0 or nums[index-1].second>=nums[prev-1].second){
            include= nums[index-1].second + solve(nums,index+1,index,dp);
        }
        
        notinclude= solve(nums,index+1,prev,dp);
        
        return dp[index][prev]=max(include,notinclude);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> nums;
        
        for(int i=0;i<ages.size();i++){
            nums.push_back({ages[i],scores[i]});
        }
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        
        return solve(nums,1,0,dp);
    }
};