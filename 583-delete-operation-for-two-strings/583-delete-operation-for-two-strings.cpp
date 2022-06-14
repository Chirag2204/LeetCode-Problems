class Solution {
public:
    int solve(string &word1,string &word2,int m,int n,vector<vector<int>>& dp){
        if(m==0 || n==0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(word1[m-1]==word2[n-1]){
            dp[m][n]=1+solve(word1,word2,m-1,n-1,dp);
        }else{
            dp[m][n]=max(solve(word1,word2,m-1,n,dp),solve(word1,word2,m,n-1,dp));
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        
        int m=word1.length(),n=word2.length();
        vector<vector<int>>dp(m+2,vector<int>(n+2,-1));
        int l=solve(word1,word2,m,n,dp);
        return (m-l)+(n-l);
    }
};