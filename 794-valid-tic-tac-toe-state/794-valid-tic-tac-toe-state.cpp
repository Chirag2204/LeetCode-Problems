class Solution {
public:
    bool checkwinner(vector<string>& board,char& c){
        if(board[0][0]==c && board[0][0]==board[0][1]&& board[0][1]==board[0][2])return true;
        if(board[1][0]==c && board[1][0]==board[1][1]&& board[1][1]==board[1][2])return true;
        if(board[2][0]==c && board[2][0]==board[2][1]&& board[2][1]==board[2][2])return true;
        if(board[0][0]==c && board[0][0]==board[1][0]&& board[1][0]==board[2][0])return true;
        if(board[0][1]==c && board[0][1]==board[1][1]&& board[1][1]==board[2][1])return true;
        if(board[0][2]==c && board[0][2]==board[1][2]&& board[1][2]==board[2][2])return true;
        if(board[0][0]==c && board[0][0]==board[1][1]&& board[1][1]==board[2][2])return true;
        if(board[2][0]==c && board[2][0]==board[1][1]&& board[1][1]==board[0][2])return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int co=0, cx=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].length();j++){
                if(board[i][j]=='X')cx++;
                if(board[i][j]=='O')co++;
            }
        }
        if(cx-co>1 || cx-co<0)return false;
        char x='X',o='O';
        if(checkwinner(board,x)&&co==cx)return false;
        if(checkwinner(board,o)&&co<cx)return false;
        if(checkwinner(board,x)&&checkwinner(board,o))return false;
        return true;
    }
};