class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ans(m,-1);
        for(int j=0;j<m;j++){
            int dest=1;
            int i=0,k=j;
            for(i=0;i<n;i++){
                if((grid[i][k]==-1 and (k==0 or grid[i][k-1]==1)) or (grid[i][k]==1 and (k==m-1 or grid[i][k+1]==-1))){
                    dest=0;
                    break;                                                                                      }
                if(grid[i][k]==-1)k--;
                 if(grid[i][k]==1)k++;
              
                
                
                //cout<<i<<" "<<k<<endl;
                
            }
            // cout<<"---------"<<endl;
            // cout<<i<<" ->"<<k<<" ->"<<j<<endl;
            if(dest)ans[j]=k;
            else ans[j]=-1;
        }
        return ans;
    }
};