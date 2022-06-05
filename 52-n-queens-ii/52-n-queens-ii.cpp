class Solution {
public:
     bool check(vector<string>& q,int row,int col,int n){
        //column check
        for(int i=0;i<row;i++){
            if(q[i][col]=='Q')return false;
        }
        
        //diagonal check
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(q[i][j]=='Q')return false;
        }
        
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(q[i][j]=='Q')return false;
        }
        return true;
    }
    
    void solve(int& count,vector<string> q,int row,int n){
        if(row==n){
            count++;
            return ;
        }
        for(int j=0;j<n;j++){
            if(check(q,row,j,n)){
               q[row][j]='Q';
                solve(count,q,row+1,n);
                q[row][j]='.'; //backtracking
           }
         }  
       }
 
    
    int totalNQueens(int n) {
         vector<vector<string>> ans;
        vector<string>q (n,string(n,'.'));
        int count=0;
        solve(count,q,0,n);
        return count;
    }
};