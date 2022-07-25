class Solution {
public:
    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j){
      if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size() || grid2[i][j]==0)
          return true;
        
      if(grid1[i][j]!=1)return false;
        
        grid2[i][j]=0;
    
        bool res1=dfs(grid1,grid2,i-1,j);
        bool res2=dfs(grid1,grid2,i+1,j);
        bool res3=dfs(grid1,grid2,i,j-1);
        bool res4=dfs(grid1,grid2,i,j+1);
        
        return res1&&res2&&res3&&res4;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1){
                    bool match=dfs(grid1,grid2,i,j);
                    if(match)count++;
                } 
            }
        }
        return count;
    }
};