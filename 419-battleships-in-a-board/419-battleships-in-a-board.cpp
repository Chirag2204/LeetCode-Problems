class Solution {
public:
    void dfs(vector<vector<char>>& board,int x,int y){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!='X')return;
        
        board[x][y]='.';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    ans++;
                    dfs(board,i,j);
                }
            }
        }
        return ans;
    }
};