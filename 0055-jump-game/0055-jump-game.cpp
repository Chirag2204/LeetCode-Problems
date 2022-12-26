class Solution {
public:
    bool solve(vector<int>& nums,int index,vector<int>& dp){
        if(index==nums.size()-1)return 1;
        
        if(dp[index]!=-1)return dp[index];
 
        for(int i=1;i<=nums[index];i++){
            if(solve(nums,index+i,dp))
           return dp[index]=true;
        }
        // cout<<res<<" "<<index<<endl;
        return dp[index]=false;
    }
    
    bool canJump(vector<int>& nums) {
       vector<int> dp(10002,-1);
         bool ans=solve(nums,0,dp);
        return ans;
        
        
    }
    
};