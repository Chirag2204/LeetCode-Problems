class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& m,vector<int>& visited,vector<int>& cyclicvisited,int val){
        visited[val]=1;
        cyclicvisited[val]=1;
        for(int& i:m[val]){
            if(visited[i]==0){
               if( dfs(m,visited,cyclicvisited,i))return true;
           }else if(cyclicvisited[i]){
               return true;
           }
        }
        cyclicvisited[val]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<int> visited(numCourses,0);
        vector<int> cyclicvisited(numCourses,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<p.size();i++){
            m[p[i][0]].push_back(p[i][1]);
        }
        for(auto& x:m){
            int val=x.first;
            bool ans=dfs(m,visited,cyclicvisited,val);
            // cout<<val<<" "<<ans<<endl;
            if(ans)return false;
        }
        return true;
    }
};