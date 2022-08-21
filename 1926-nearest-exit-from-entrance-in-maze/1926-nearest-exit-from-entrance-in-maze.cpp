class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        queue<pair<pair<int,int>,int>> q;
        q.push({{ent[0],ent[1]},0});
        while(!q.empty()){
           int x=q.front().first.first;
           int y=q.front().first.second;
           int l=q.front().second;
            q.pop();
            maze[x][y]='+';
            //up
            if(x>0 and maze[x-1][y]=='.'){
                if(x-1==0 or y==0 or y==maze[0].size()-1 or x-1==maze.size()-1)return l+1;
                maze[x-1][y]='+';
                q.push({{x-1,y},l+1});
            }
            //down
            if(x<maze.size()-1 and maze[x+1][y]=='.'){
                if(x+1==0 or y==0 or y==maze[0].size()-1 or x+1==maze.size()-1)return l+1;
                maze[x+1][y]='+';
                q.push({{x+1,y},l+1});
            }
            
            //left
            if(y>0 and maze[x][y-1]=='.'){
                if(x==0 or y-1==0 or y-1==maze[0].size()-1 or x==maze.size()-1)return l+1;
                maze[x][y-1]='+';
                q.push({{x,y-1},l+1});
            }
            
            //right
             if(y<maze[0].size()-1 and maze[x][y+1]=='.'){
                if(x==0 or y+1==0 or y+1==maze[0].size()-1 or x==maze.size()-1)return l+1;
                maze[x][y+1]='+';
                q.push({{x,y+1},l+1});
            }
        }
        return -1;
    }
};