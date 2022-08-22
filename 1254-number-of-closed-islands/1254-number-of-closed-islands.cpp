class Solution {
public:
    bool bfs(vector<vector<int>>& grid,int i,int j){
        bool ans=true;
        
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            grid[x][y]=1;
            if(x==0 or x==grid.size()-1 or y==0 or y==grid[0].size()-1)ans=false;
            if(x>0 and grid[x-1][y]==0){
                grid[x-1][y]=1;
                q.push({x-1,y});
            } 
            if(x<grid.size()-1 and grid[x+1][y]==0){
                grid[x+1][y]=1;
                q.push({x+1,y});
            } 
            if(y>0 and grid[x][y-1]==0){
                grid[x][y-1]=1;
                q.push({x,y-1});
            } 
            if(y<grid[0].size()-1 and grid[x][y+1]==0){
                grid[x][y+1]=1;
                q.push({x,y+1});
            } 
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==0){
                    if(bfs(grid,i,j))count++;
                    // cout<<i<<" "<<j<<" "<<count<<endl;
                }
            }
        }
        return count;
    }
};