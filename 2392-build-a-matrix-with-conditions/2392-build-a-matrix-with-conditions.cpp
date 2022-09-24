class Solution {
public:
    vector<int> toposort(map<int,vector<int>>& m,int& k){
        vector<int> indegree(k+1,0);
        for(auto& x:m){
           for(int& i:x.second){
               indegree[i]++;
           }
        }
        
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int n=q.front();
            ans.push_back(n);
            q.pop();
            for(int &i:m[n]){
                indegree[i]--;
                if(indegree[i]==0)q.push(i);
            }
        }
        return ans;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<vector<int>> ans;
        map<int,vector<int>> rpos;
        for(int i=0;i<row.size();i++){
            rpos[row[i][0]].push_back(row[i][1]);
        }
        
        vector<int> rows=toposort(rpos,k);
        if(rows.size()!=k)return ans;
        
         map<int,vector<int>> cpos;
        for(int i=0;i<col.size();i++){
            cpos[col[i][0]].push_back(col[i][1]);
        }
        
        vector<int> cols=toposort(cpos,k);
        if(cols.size()!=k)return ans;
        
        ans.resize(k,vector<int>(k,0));
        
        map<int,pair<int,int>> pos;
        for(int i=0;i<k;i++){
            pos[rows[i]].first=i;
            pos[cols[i]].second=i;
        }
        
        for(auto& x:pos){
            ans[x.second.first][x.second.second]=x.first;
        }
        return ans;
    }
};