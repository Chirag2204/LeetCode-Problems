class Solution {
public:
     void solve(vector<vector<int>>& grid,int i,int j,int& count){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=1)return;
        grid[i][j]=0;
         count++;
         solve(grid,i-1,j,count);
         solve(grid,i+1,j,count);
         solve(grid,i,j+1,count);
         solve(grid,i,j-1,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    solve(grid,i,j,count);
                    ans=max(ans,count);
                    // cout<<i<<" "<<j<<" "<<count<<endl;
                    
                    count=0;
                }
            }
        }
        return ans;
    }
};