class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==0)return ;
        
        grid[i][j]=0;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    //check to all ones which are connected to ones with boundaries
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            dfs(grid,i,0);
            dfs(grid,i,grid[0].size()-1);
        }
        
        for(int i=0;i<grid[0].size();i++){
            dfs(grid,0,i);
            dfs(grid,grid.size()-1,i);
        }
        
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                if(grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};