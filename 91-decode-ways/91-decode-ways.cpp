class Solution {
public:
    int solve(string& s,int index,int prev,vector<vector<int>>& dp){
      if(index>s.length())return 1;
        
      if( dp[index][prev]!=-1)return dp[index][prev];
        
        int include1=0,include2=0;
        if(s[index-1]!='0'){
            include1=solve(s,index+1,index,dp);
            if(index<s.length() and (s[index-1]<'2' or(s[index-1]=='2' and s[index]<='6')))
                include2=solve(s,index+2,index,dp);
        }
        
        return dp[index][prev]=include1+include2;
        
    }
    
    int numDecodings(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='0' and (i==0 or s[i-1]>'2'))return 0;
        }
        
        vector<vector<int>> dp(s.length()+2,vector<int>(s.length()+2,-1));
        return solve(s,1,0,dp);
    }
};