class Solution {
public:
    void dfs(vector<vector<int>>& graph,int val,vector<int> temp,vector<vector<int>>& ans){
        temp.push_back(val);
        if(val==graph.size()-1){
           
            ans.push_back(temp);
            return ;
        }
        
        for(int& i: graph[val]){
            
            dfs(graph,i,temp,ans);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph,0,temp,ans);
        return ans;
    }
};