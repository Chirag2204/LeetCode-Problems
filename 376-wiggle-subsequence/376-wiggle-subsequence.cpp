class Solution {
public:
    int solve(vector<int>& difs,int index,int prev,vector<int>& dp){
      if(index>=difs.size())return 0;
        
        if(dp[prev+1]!=-1)return dp[prev+1];
        
        int include=0;
        if(prev==-1 || (difs[index] > 0 && difs[prev]<0 ) || (difs[index]<0 && difs[prev]>0)){
            include=1+solve(difs,index+1,index,dp);
        }
        int notinclude=solve(difs,index+1,prev,dp);
        
        return dp[prev+1]=max(include,notinclude);
        
        
    }
    
    int wiggleMaxLength(vector<int>& nums){
      
        vector<int> difs;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]!=0)
            difs.push_back(nums[i]-nums[i-1]);
        }
        
        vector<int> dp(nums.size(),-1);
        int prev=-1;
        return 1+solve(difs,0,prev,dp);
    }
};