class Solution {
public:
    int solve(string& s,string& t,int index1,int index2,vector<vector<int>>& dp){
        if(index2==t.length() )return 1;
        
        if(index1==s.length())return 0;
        
        
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        int take=0,nottake=0;
        if(s[index1]==t[index2])take=solve(s,t,index1+1,index2+1,dp);
        nottake=solve(s,t,index1+1,index2,dp);
        
        return dp[index1][index2]=take+nottake;
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length(),-1));
        return solve(s,t,0,0,dp);
    }
};