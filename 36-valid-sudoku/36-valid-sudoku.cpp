class Solution {
public:
    bool checkrow(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && s.count(board[i][j]))return false;
                s.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool checkcol(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.' && s.count(board[j][i]))return false;
                s.insert(board[j][i]);
            }
        }
        return true;
    }
    
    bool checkbox(vector<vector<char>>& board){
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<char>s;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.' && s.count(board[x][y]))return false;
                        s.insert(board[x][y]);
                    }
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkrow(board)&&checkcol(board)&&checkbox(board);
    }
};