class Solution {
public:
    
    void dfs(vector<vector<int>>& heights,int i,int j,vector<vector<bool>>& dp){
       if(i<0 or i>=heights.size() or j<0  or j>=heights[0].size() or dp[i][j])return ;
        
        dp[i][j]=1;
        if(i>0 and heights[i][j]<=heights[i-1][j])
        dfs(heights,i-1,j,dp);
        if(i<heights.size()-1 and heights[i][j]<=heights[i+1][j])
        dfs(heights,i+1,j,dp);
        if(j>0 and heights[i][j]<=heights[i][j-1])
        dfs(heights,i,j-1,dp);
        if(j<heights[0].size()-1 and heights[i][j]<=heights[i][j+1])
        dfs(heights,i,j+1,dp); 
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>> dpp(n+1,vector<bool>(m+1,false));
        vector<vector<bool>> dpa(n+1,vector<bool>(m+1,false));
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            dfs(heights,i,0,dpp);
            dfs(heights,i,m-1,dpa);
        }
        for(int i=0;i<m;i++){
            dfs(heights,0,i,dpp);
            dfs(heights,n-1,i,dpa);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dpp[i][j] and dpa[i][j])ans.push_back({i,j});
             
            }
            
        }
        return ans;
    }
};