class Solution {
public:
    vector<int> vis;
    vector<int> ans;
    
    map<char,int> solve(int val,map<int,vector<int>>& m,string& labels){
        map<char,int> ret;
        if(vis[val])return ret;
        
        ret[labels[val]]++;
        vis[val]=1;
        map<char,int> temp;
        for(auto& x:m[val]){
            temp=solve(x,m,labels);
                for(auto& k:temp){
                    ret[k.first]+=k.second;
                }
        }
        ans[val]=ret[labels[val]];
        return ret;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        map<int,vector<int>> m; //int int,char
        
        for(auto& x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        vis.resize(n,0);
        ans.resize(n,0);
        solve(0,m,labels);
        return ans;
        
    }
};