class Solution {
public:
    int mod=1e9+7;
    int solve(string &s,int i, int& k,string str,vector<int>& dp){
        if(i>=s.length())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        
        for(int j=i;j<s.length();j++){
            str.push_back(s[j]);
            if(stol(str)>k)break;
            ans+=solve(s,j+1,k,"",dp);
            ans%=mod;
        }
        return dp[i]=ans;
        
    }
    
    int numberOfArrays(string s, int k) {
        string str="";
        vector<int> dp(s.length()+1,-1);
        return solve(s,0,k,str,dp);
    }
};