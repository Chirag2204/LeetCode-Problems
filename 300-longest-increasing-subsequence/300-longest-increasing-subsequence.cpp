class Solution {
public:
//     int solve(vector<int>&nums,int prev,int index,vector<vector<int>>& dp){
//         if(index>nums.size())return 0;
//         if(dp[index][prev]!=-1)return dp[index][prev];
//         int include=0,notinclude=0;
//         if(prev==0 || nums[index-1]>nums[prev-1]){
//           include=1+solve(nums,index,index+1,dp);  
//         }
//           notinclude=solve(nums,prev,index+1,dp);
        
//         return dp[index][prev]=max(include,notinclude);     
        
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
       
//         vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+1,-1));
//         return solve(nums,0,1,dp);
        
//     }
    //Alternate
    
    
    int lengthOfLIS(vector<int>& nums) {
       
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            auto index=lower_bound(temp.begin(),temp.end(),nums[i]);
            if(index-temp.begin()>=temp.size()){
                temp.push_back(nums[i]);
            }else{
                temp[index-temp.begin()]=nums[i];
            }
        }
        return temp.size();
        
    }
    
};