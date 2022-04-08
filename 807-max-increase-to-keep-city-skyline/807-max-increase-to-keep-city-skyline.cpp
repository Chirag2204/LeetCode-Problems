class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> maxrow(n,0);
        vector<int> maxcol(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maxrow[i]<grid[i][j])
                    maxrow[i]=grid[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(maxcol[i]<grid[j][i])
                    maxcol[i]=grid[j][i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=min(maxrow[i],maxcol[j])-grid[i][j];
                grid[i][j]=min(maxrow[i],maxcol[j]);
            }
        }
        return ans;
    }
};