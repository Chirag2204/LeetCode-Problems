class Solution {
public:
    int solve(string& text1,string& text2,int index1,int index2,vector<vector<int>>& dp){
       if(index1==text1.size() || index2==text2.size())return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        int match=0,move1=0,move2=0;
        if(text1[index1]==text2[index2]){
            match=1+solve(text1,text2,index1+1,index2+1,dp);
        }else{
            move1=solve(text1,text2,index1+1,index2,dp);
            move2=solve(text1,text2,index1,index2+1,dp);
        }
        return dp[index1][index2]= max(match,max(move1,move2));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1,text2,0,0,dp);
    }
};