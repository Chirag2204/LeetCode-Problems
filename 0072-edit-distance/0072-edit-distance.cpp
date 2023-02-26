class Solution {
public:
    int solve(string &word1,string& word2,int index1,int index2,vector<vector<int>>& dp){
       if(index2==word2.length())return  word1.length()-index1;//have to delete these no. of elements from word1
        if(index1==word1.length())return word2.length()-index2;//have to insert these number of elements in word1
        
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        int match=10000,replace=10000,remove=10000,insert=10000;
        
        if(word1[index1]==word2[index2])match=solve(word1,word2,index1+1,index2+1,dp);
        else{
        insert=1+solve(word1,word2,index1,index2+1,dp);
        replace=1+solve(word1,word2,index1+1,index2+1,dp);
        remove=1+solve(word1,word2,index1+1,index2,dp);
        }
        
        return dp[index1][index2]=min(match,min(replace,min(insert,remove)));
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};