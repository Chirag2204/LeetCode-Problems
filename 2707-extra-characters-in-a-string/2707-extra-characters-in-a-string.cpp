class Solution {
public:
    int solve(string& s,unordered_set<string>& st,int index,vector<int>& dp){
       if(index>=s.length())return 0;
        if(dp[index]!=-1)return dp[index];
        
       int seperate=1e5;
        
       seperate = 1+ solve(s,st,index+1,dp);
       for(int i=1;i+index<=s.length();i++){
           if(st.count(s.substr(index,i))) seperate= min(seperate,solve(s,st,index+i,dp));
       }
        
       return dp[index]= seperate;
       
    }
    
    int minExtraChar(string s, vector<string>& dict) {
       unordered_set<string> st(dict.begin(),dict.end());
        vector<int> dp(s.length()+1,-1);
        int covered= solve(s,st,0,dp);
        
        return covered;
        
    }
};