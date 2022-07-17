// class Solution {
// public:
//     int solve(int &m,int &n,int cr,int cc,int moves,vector<vector<vector<int>>>& dp){
//         if(moves>=0 && (cr>=m || cr<0 || cc<0 || cc>=n))return 1;
//         if(moves==0)return 0;
//          if(dp[cr][cc][moves]!=-1)return dp[cr][cc][moves];
//         long long up=solve(m,n,cr-1,cc,moves-1,dp);
//         long long down=solve(m,n,cr+1,cc,moves-1,dp);
//         long long left=solve(m,n,cr,cc-1,moves-1,dp);
//         long long right=solve(m,n,cr,cc+1,moves-1,dp);
        
//         return dp[cr][cc][moves]= (up+down+left+right)%1000000007;
//     }
    
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//         vector<vector<vector<int>>>dp (m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
//         return solve(m,n,startRow,startColumn,maxMove,dp);
//     }
// };

class Solution {
 const int mod =1e9 +7;
const int dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};

public:
 int solve(int &m,int &n,int cr,int cc,int moves,vector<vector<vector<int>>>& dp){
     
    if(moves>=0 && (cr>=m || cr<0 || cc<0 || cc>=n))return 1;
    if(moves==0)return 0;
    if(dp[cr][cc][moves]!=-1)return dp[cr][cc][moves];
     
       dp[cr][cc][moves] =0;
     for (int i=0;i<4;i++){
         dp[cr][cc][moves]= 
             ( dp[cr][cc][moves]+ 
               solve(m,n,cr + dir[i][0], cc+ dir[i][1],moves-1,dp)) %mod ;
     }
     return dp[cr][cc][moves];
 }
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
   
    vector<vector<vector<int>>>dp (m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
   return solve(m,n,startRow,startColumn,maxMove,dp);
}

};