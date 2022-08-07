class Solution {
public:
    vector<char> vowels{'a','e','i','o','u'};
    int solve(int target,int prev,vector<vector<int>>& dp){
       if(target==0)return 1;
        
        if(dp[target][prev]!=-1)return dp[target][prev];
        
        
        long long sum=0;
        if(prev==0){
           sum+=solve(target-1,1,dp); 
        }
        if(prev==1){
            sum+=solve(target-1,0,dp);
            sum+=solve(target-1,2,dp);
        }
        if(prev==2){
            sum+=solve(target-1,0,dp);
            sum+=solve(target-1,1,dp);
            sum+=solve(target-1,3,dp);
            sum+=solve(target-1,4,dp);
        }
        if(prev==3){
            sum+=solve(target-1,2,dp);
            sum+=solve(target-1,4,dp);
        }
        if(prev==4){
            sum+=solve(target-1,0,dp);
        }
        return dp[target][prev]=(int)(sum%(1000000007));
        
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        long long ans=0;
        for(int i=0;i<5;i++){
            ans+=solve(n-1,i,dp);
        }
        return int(ans%(1000000007));
    }
};