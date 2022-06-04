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
    
    void solve(vector<vector<string>>& ans,vector<string> q,int row,int n){
        if(row==n){
            ans.push_back(q);
            return ;
        }
        for(int j=0;j<n;j++){
            if(check(q,row,j,n)){
               q[row][j]='Q';
                solve(ans,q,row+1,n);
                q[row][j]='.'; //backtracking
           }
         }  
       }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>q (n,string(n,'.'));
        solve(ans,q,0,n);
        return ans;
    }
};