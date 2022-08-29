class Solution {
public:
    void dfs(vector<vector<char>>& board,int x,int y){
        if(x<0 or x>=board.size() or y<0 or y>=board[0].size() or board[x][y]!='O')return ;
        
        board[x][y]='Y';
        dfs(board,x-1,y);
        dfs(board,x+1,y);
        dfs(board,x,y-1);
        dfs(board,x,y+1);
    }
    void solve(vector<vector<char>>& board) {
        cout<<"here 1"<<endl;
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')dfs(board,0,i);
        }
        cout<<"here 2"<<endl;
        for(int i=0;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O')dfs(board,board.size()-1,i);
        }
        cout<<"here 3"<<endl;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')dfs(board,i,0);
        }
        cout<<"here 4"<<endl;
        for(int i=0;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O')dfs(board,i,board[0].size()-1);
        }
        cout<<"here 5"<<endl;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='Y')board[i][j]='O';
            }
        }
    }
};