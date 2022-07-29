class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dir {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+dir[i][0];
                int newy=y+dir[i][1];
                
                if(newx>=0 && newx<mat.size() && newy>=0 && newy<mat[0].size() && ans[newx][newy]==-1){
                    q.push({newx,newy});
                    ans[newx][newy]=1+ans[x][y];
                }
            }
        }
        
        return ans;
    }
};