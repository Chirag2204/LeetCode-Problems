class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        map<int,vector<int>> m;
        for(auto& x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        int ans=0;
        for(auto& x:m){
            if(x.second.size()==n)ans=x.first;
        }
        return ans;
    }
};