class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int  x,int y){
        return (x>=0 and y>=0 and x<grid.size() and y<grid[0].size() and grid[x][y]!=-1);
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        
        int n=grid.size(),m=grid[0].size();
        queue<pair<pair<pair<int,int>,int>,int>> q;// coords dist k
        
        if(grid[0][0]==1)k--;
        
        q.push({{{0,0},0},k});
        grid[0][0]=-1;
        
        while(!q.empty()){
            pair<pair<pair<int,int>,int>,int> f=q.front();
            q.pop();
            
            int x=f.first.first.first;
            int y=f.first.first.second;
            int dist=f.first.second;
            int rem=f.second;
            //cout<<x<<" "<<y<<" "<<dist<<" "<<rem<<endl;
            if(x==n-1 and y==m-1)return dist;
            
            
            if(grid[x][y]==1){
                if(rem>0)rem--;
                else continue;
            }
            
            if(vis[x][y]!=-1 && vis[x][y]>=rem)
                continue;
            vis[x][y]=rem;
            
            if(isValid(grid,x-1,y))
               q.push({{{x-1,y},dist+1},rem});
            
            if(isValid(grid,x+1,y))
               q.push({{{x+1,y},dist+1},rem});
            
            if(isValid(grid,x,y-1))
               q.push({{{x,y-1},dist+1},rem});
            
            if(isValid(grid,x,y+1))
               q.push({{{x,y+1},dist+1},rem});
            
            
        }
       
        return -1;
    }
};