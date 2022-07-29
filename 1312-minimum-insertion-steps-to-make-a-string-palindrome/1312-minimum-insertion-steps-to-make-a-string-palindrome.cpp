class Solution {
public:
    int solve(string &s,int start,int end,vector<vector<int>>& dp){
        if(start>end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
       int include=0,notincs=0,notince=0;
       if(s[start]==s[end]){
           include=min(2,end-start+1)+solve(s,start+1,end-1,dp);
       }
       notincs=solve(s,start+1,end,dp);
       notince=solve(s,start,end-1,dp);
       
       return dp[start][end]= max(include,max(notincs,notince));
    }
    
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
      return s.length()-solve(s,0,s.length()-1,dp);
    }
};