class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans=board;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                if(i>0 && j>0)
                if(board[i-1][j-1])count++;
                if(i>0)
                if(board[i-1][j])count++;
                if(i>0 && j<m-1)
                if(board[i-1][j+1])count++;
                if( j<m-1)
                if(board[i][j+1])count++;
                if(i<n-1 && j<m-1)
                if(board[i+1][j+1])count++;
                if(i<n-1 )
                if(board[i+1][j])count++;
                if(i<n-1 && j>0)
                if(board[i+1][j-1])count++;
                if( j>0)
                if(board[i][j-1])count++;
                
                if(count<=1)
                    ans[i][j]=0;
                if(count==3)
                    ans[i][j]=1;
                if(count>3)
                    ans[i][j]=0;
            }
        }
        board=ans;
    }
};