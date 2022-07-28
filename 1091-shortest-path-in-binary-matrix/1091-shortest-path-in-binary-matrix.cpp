class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        if(grid[0][0]==0 &&  grid.size()==1)return 1;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        q.push({{0,0},1});
        visited[0][0]=1;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            
            q.pop();
            vector<vector<int>> dir={{-1,0},{1,0},{-1,-1},{0,1},{0,-1},{1,1},{-1,1},{1,-1}};
            for(int i=0;i<8;i++){
                int newx=x+dir[i][0];
                int newy=y+dir[i][1];
                
        if(newx>=0 && newx<grid.size()&&newy>=0 && newy<grid[0].size() && grid[newx][newy]==0 && visited[newx][newy]==0){
                   if(newx==grid.size()-1 && newy==grid[0].size()-1)return dist+1;
                    q.push({{newx,newy},dist+1}); 
                    visited[newx][newy]=1;
                }
            }
        }
        return -1;
    }
};