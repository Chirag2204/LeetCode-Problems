class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &m,vector<int>& visited,int val){
        if(visited[val])return ;
        visited[val]=1;
        for(auto& x:m[val]){
            dfs(m,visited,x);
        }
    }
    
    int findCircleNum(vector<vector<int>>& nums) {
      unordered_map<int,vector<int>> m;
        int n=nums.size();
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(nums[i][j]){
                 m[i].push_back(j);
                  m[j].push_back(i);
              }
          }
      }
        int ans=0;
        vector<int> visited(n+1,0);
        for(auto& s:m){
           if(visited[s.first]==0) {
               ans++;
               int val=s.first;
               dfs(m,visited,val);
           }
        }
        return ans;
    }
};