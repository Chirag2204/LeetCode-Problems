class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int count0=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0)count0++;
            }
        }
        if(count0==0)return 0;
        int ans=1e5;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){
                            if(grid[x][y]>1){
                                grid[x][y]--;
                                grid[i][j]++;
                                ans=min(ans,abs(x-i)+abs(y-j)+ minimumMoves(grid));
                                grid[x][y]++;
                                grid[i][j]--;
                                
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};