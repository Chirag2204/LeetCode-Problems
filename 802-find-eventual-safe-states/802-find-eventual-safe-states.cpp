class Solution {
public:
    /// one method is using cycle detection dfs
    
    //here reverse the links of the graph and perform toposort
    //we will get only those elements which are acyclic
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> indegree(graph.size(),0);
        map<int,vector<int>> m;
        
        int index=0;
        for(auto& x:graph){
           for(int i=0;i<x.size();i++){
               m[x[i]].push_back(index);
               indegree[index]++;
           } 
            index++;
        }
        
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            
            for(auto& x:m[t]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};