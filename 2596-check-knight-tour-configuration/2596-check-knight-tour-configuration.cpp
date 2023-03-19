class Solution {
public:
    vector<vector<int>> dirs{{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
     bool isValid(int x,int y,int count,vector<vector<int>>& grid){
         return x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y]==count;
     }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
    
        bool found=false;
        int x=0,y=0;
        while(count<n*m){
            found=false;
            //cout<<x<<" "<<y<<" "<<count<<endl;
            for(int i=0;i<8;i++){
                if(isValid(x+dirs[i][0],y+dirs[i][1],count+1,grid)){
                    found=true;
                    x+=dirs[i][0];
                    y+=dirs[i][1];
                    //count++;
                    break;
                }
            }
            count++;
            if(!found and count<n*m)return false;
        }
        return true;
    }
};