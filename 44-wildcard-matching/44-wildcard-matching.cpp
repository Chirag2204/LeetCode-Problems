class Solution {
public:
    bool solve(string& s,string& p,int index1,int index2,vector<vector<int>>& dp){
        if(index1==s.length() && index2==p.length())return true;
        
        if(index1==s.length()){
           for(int i=index2;i<p.length();i++){
               if(p[i]!='*')return false;
           }
            return true;
        }
        if(dp[index1][index2]!=-1)return dp[index1][index2];

        if(s[index1]==p[index2] or p[index2]=='?'){
            return dp[index1][index2]=solve(s,p,index1+1,index2+1,dp);
        }
        if(p[index2]=='*'){
            return dp[index1][index2]=solve(s,p,index1+1,index2,dp) or solve(s,p,index1,index2+1,dp);
        }
        return dp[index1][index2]=false;
        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,0,0,dp);
    }
};