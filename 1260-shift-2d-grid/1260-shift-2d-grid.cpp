class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans=grid;
        int n=grid.size(),m=grid[0].size();
        int xinc=k/m,yinc=k%m;
        // cout<<xinc<<" "<<yinc<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               int newx=i+xinc;
                int newy=j+yinc;
                // cout<<newx<<" "<<newy<<endl;
                while(newy>=m){
                    // cout<<"came in if y at"<<j<<endl;
                    newy=newy-m;
                    newx++;
                }
                while(newx>=n){
                    // cout<<"came in if x at"<<i<<endl;
                    newx=newx-n;
                }
                ans[newx][newy]=grid[i][j];
            }
        }
        return ans;
    }
};