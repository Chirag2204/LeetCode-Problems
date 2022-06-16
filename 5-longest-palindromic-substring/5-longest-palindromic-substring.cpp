class Solution {
public:
    bool solve(string& s,vector<int>&ans,int start,int end,vector<vector<int>>& dp){
        if(start>=end)return true;
        
        if(dp[start][end]!=-1)return dp[start][end];
        bool found=false;
        if(s[start]==s[end]){
            found=true && solve(s,ans,start+1,end-1,dp);
        }
        
        solve(s,ans,start+1,end,dp);
        solve(s,ans,start,end-1,dp);
        
        if(found && end-start > ans[1]-ans[0]){
            ans[0]=start;
            ans[1]=end;
        }
        return dp[start][end]=found;
        
    }
    
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        vector<int>ans(2,0);
        solve(s,ans,0,n-1,dp);
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
};