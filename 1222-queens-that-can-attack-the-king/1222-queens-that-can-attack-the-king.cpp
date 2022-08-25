class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<int>>board (8,vector<int>(8,0));
          int x=king[0];
        int y=king[1];
        board[x][y]=1;
        for(int i=0;i<queens.size();i++){
            board[queens[i][0]][queens[i][1]]=2;
        }
        //check row
        for(int i=y-1;i>=0;i--){
            if(board[x][i]==2){
                ans.push_back({x,i});
                break;
            }
        }
        for(int i=y+1;i<8;i++){
            if(board[x][i]==2){
                ans.push_back({x,i});
                break;
            }
        }
        
        // col check
        for(int i=x-1;i>=0;i--){
            if(board[i][y]==2){
                ans.push_back({i,y});
                break;
            }
        }
        for(int i=x+1;i<8;i++){
            if(board[i][y]==2){
                ans.push_back({i,y});
                break;
            }
        }
        //check diagonals
        int i=x,j=y;
        while(i>=0 and j>=0){
            if(board[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            i--;
            j--;
        }
        i=x,j=y;
        while(i>=0 and j<8){
            if(board[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            i--;
            j++;
        }
        i=x,j=y;
        while(i<8 and j>=0){
            if(board[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            i++;
            j--;
        }
        i=x,j=y;
        while(i<8 and j<8){
            if(board[i][j]==2){
                ans.push_back({i,j});
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
};