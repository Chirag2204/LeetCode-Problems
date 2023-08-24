class Solution {
public:
    int solve(int index,vector<int>& nums,int num,vector<vector<int>>& dp){
        if(index>=nums.size())return 0;
        
        int change=1e5,notchange=1e5;
        if(nums[index]==num){
            notchange= solve(index+1,nums,num,dp);
        }
        else{
            if(nums[index]>num)notchange=solve(index+1,nums,nums[index],dp);
            change= 1+ solve(index+1,nums,num,dp);
        }
        //cout<<index<<" "<<change<<","<<notchange<<endl;
        return dp[index][num]= min(change,notchange);
        
    }
    
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(4,-1));
       return solve(0,nums,1,dp);
    }
};