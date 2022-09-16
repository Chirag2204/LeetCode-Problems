class Solution {
public:
    int solve(vector<int>& nums,vector<int>& multi,int index1,int index2,vector<vector<int>>& dp){
        if(index1>multi.size() )return 0;
        if(dp[index1][index2]!=INT_MIN)return dp[index1][index2];
    
        int front=multi[index1-1]*nums[index2-1] + solve(nums,multi,index1+1,index2+1,dp) ;
        
        int back=multi[index1-1]*nums[nums.size()-1-(index1-index2)] + solve(nums,multi,index1+1,index2,dp) ;
        
        
        return dp[index1][index2]=max(front,back);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n=nums.size(),m=multi.size();
        
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        
        return solve(nums,multi,1,1,dp);
    }
    
    //top down
//     int maximumScore(vector<int>& nums, vector<int>& multi) {
//         int n=nums.size(),m=multi.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
//         for(int i=0;i<n-1;i++){
//             dp[i][0]=0;
//             dp[n-1][i]=0;
//         }
        
//         for(int i=n-2;i>=0;i--){
//             for(int j=n-2;j>=0;j--){
//                 int front=multi[i]*nums[j] + dp[i+1][j+1] ;
//                 int back=multi[i]*nums[nums.size()-(i-j)] + dp[i+1][j] ;
                
//                 dp[i][j]=max(front,back);
//             }
//         }
//         return dp[0][0];
//     }
};